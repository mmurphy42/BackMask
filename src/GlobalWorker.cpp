#include "GlobalWorker.h"
#include <iterator>

std::vector<std::multimap<int, std::pair<std::string, int>>> GlobalWorker::m_thread_results(MAX_NUM_THREADS);

uint64_t GlobalWorker::m_cur_thread_id{0};

GlobalWorker::GlobalWorker(std::istream& words_stream, std::istream& bigrams_stream)
    : m_thread_workers(), m_bigrams(), m_results(), m_results_lock(), m_phrase_results()
{
    m_search_trie_root = new StringViewMaskTrieNode();
    for (std::string line; std::getline(words_stream, line);) {
        // Sanitize and insert.
        sanitize_text(line);
        m_search_trie_root->InsertString(m_search_trie_root, std::string_view(line));
    }
        
    // Read in the bigrams.
    for (std::string line; std::getline(bigrams_stream, line);) {
        std::istringstream stream(line);
        auto str_first = std::string();
        auto str_second = std::string();
        size_t occurrences;
        
        // They are ordered: word1 word2 occurences
        stream >> str_first;
        stream >> str_second;
        stream >> occurrences;
        
        // Sanitize and insert.
        sanitize_text(str_first);
        sanitize_text(str_second);
        m_bigrams.insert(std::make_pair(str_first, std::make_pair(str_second, occurrences)));
    }
}

void GlobalWorker::GetBackWords(const std::string_view input) {
    
    // Create and initialize the thread workers.
    bit_mask bitmask = {{0}};
    spawnThreads(input, 0, m_search_trie_root, MAX_NUM_THREADS, bitmask);
    
    // Wait for the workers to finish.
    for (auto& worker : m_thread_workers) {
        worker.WaitToFinish();
    }
    
    // Merge in each workers' words.
    for (size_t i=0; i<MAX_NUM_THREADS; ++i) {
        m_results.insert(m_thread_results[i].begin(), m_thread_results[i].end());
    }
    
    // Assemble the final phrases!
    m_phrase_results = std::vector<std::vector<result_tuple>>(input.length());
    assemblePhrases();
}

void GlobalWorker::assemblePhrases() {
    size_t final_best_score = 0;
    std::string final_best_score_string = "";
    opt_size_t final_best_score_pos = 0;
    opt_size_t final_best_score_index = 0;
    
    // Loop over each starting position.
    for (size_t start_pos = 0; start_pos < m_phrase_results.size(); ++start_pos) {
        // Loop over each word in this starting position.
        for (auto[it, end_it] = m_results.equal_range(start_pos); it != end_it; ++it) {
            auto[str, end_pos] = it->second;
            // Calculate the best score for this word.
            // This can be done because we go exactly two words deep for scoring.
            size_t cur_best_score = 0;
            opt_size_t best_score_pos;
            opt_size_t best_score_index;
            auto second_words = std::unordered_map<std::string, size_t>();
            for (auto[bigrams_it, end_bigrams_it] = m_bigrams.equal_range(str); 
                 bigrams_it != end_bigrams_it;
                 ++bigrams_it) {
                second_words.insert(bigrams_it->second);
            }
            
            // If we have any trailing characters, let's see if there are any words after this one!
            if (end_pos > 0) {
                for (size_t prev_start_pos = end_pos - 1; prev_start_pos > 0; --prev_start_pos) {
                    // Loop over each word in this position, looking for the best score.
                    for (size_t prev_index = 0; prev_index < m_phrase_results[prev_start_pos].size(); ++prev_index) {
                        [[maybe_unused]] auto[score_second, str_second, unused_pos, unused_index] 
                            = m_phrase_results[prev_start_pos][prev_index];
                        auto score_it = second_words.find(str_second);
                        if (score_it != second_words.end()) {
                            size_t this_score = score_second + score_it->second;
                            if (this_score > cur_best_score) {
                                cur_best_score = this_score;
                                best_score_pos = prev_start_pos;
                                best_score_index = prev_index;
                            }
                        } else if (score_second > cur_best_score) {
                            cur_best_score = score_second;
                            best_score_pos = prev_start_pos;
                            best_score_index = prev_index;
                        }
                    }
                }
            }
            auto keyword_it = KEYWORDS.find(str);
            if (keyword_it != KEYWORDS.end()) {
                cur_best_score += (100*((*keyword_it).length()));
            }
            m_phrase_results[start_pos].push_back(std::make_tuple(cur_best_score, str, best_score_pos, best_score_index));
            
            if (cur_best_score >= final_best_score) {
                final_best_score = cur_best_score;
                final_best_score_string = str;
                final_best_score_pos = start_pos;
                final_best_score_index = m_phrase_results[start_pos].size()-1;
            }
        }
    }
    
    std::string final_phrase = "";
    while (final_best_score_pos && final_best_score_pos.value_or(0) != 0) {
        [[maybe_unused]] auto[unused_score, cur_string, next_best_score_pos, next_best_score_index]
            = m_phrase_results[final_best_score_pos.value_or(0)][final_best_score_index.value_or(0)];
        
        final_phrase.append(cur_string + " ");
        
        final_best_score_pos = next_best_score_pos;
        final_best_score_index = next_best_score_index;
    }
    // To uppercase, because it sounds scarier.
    std::transform(final_phrase.begin(), final_phrase.end(), final_phrase.begin(), ::toupper);
    std::cout << "FINAL STRING: " << final_phrase << std::endl;
}

void GlobalWorker::spawnThreads(
    const std::string_view input, 
    size_t pos, 
    const StringViewMaskTrieNode *cur_node, 
    uint32_t num_threads, 
    struct bit_mask bitmask
)
{
    size_t length = input.length();
    if (num_threads <= 1 || pos+1 > length) {
        m_thread_workers.push_back(ThreadWorker(input, pos, cur_node, bitmask, m_cur_thread_id));
        m_results_lock.lock();
        m_thread_results[m_cur_thread_id] = std::multimap<int, std::pair<std::string, int>>();
        m_results_lock.unlock();
        ++m_cur_thread_id;
    } else {
        // Try recursing with a "0".
        if (cur_node) {
            spawnThreads(
                    input, 
                    pos+1, 
                    cur_node, 
                    num_threads >> 1, 
                    bitmask
                );

            // Did we get a node?
            auto next_node = cur_node->GetNext(input, (length - pos - 1));
            if (next_node != nullptr) {
                // Check whether this is actually a word.
                auto bitmask_new = AddOneBit(pos, bitmask, length);
                if (next_node->IsWord()) {
                    auto [start_pos, end_pos] = GetBitEdges(length, bitmask_new);
                    GlobalWorker::m_results.insert(
                        std::make_pair(
                            end_pos, 
                            std::make_pair(
                                std::string_view(next_node->GetWord()), 
                                start_pos
                            )
                        )
                    );
                }
            
                // If we aren't at the end of the tree, keep recursing.
                if (next_node->HasChildren()) {
                    spawnThreads(input, pos + 1, next_node, num_threads >> 1, bitmask_new);
                }
            }
        } else {
            // Error!
            std::cerr << "ERROR: unknown node in dictionary" << std::endl;
        }
    }
}