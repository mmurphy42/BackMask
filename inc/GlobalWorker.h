#ifndef GlobalWorker_h
#define GlobalWorker_h

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <mutex>
#include <sstream>
#include <map>
#include <stack>
#include <experimental/optional>
#include "StringViewMaskTrie.h"
#include "ThreadWorker.h"
#include "BitOperations.h"

// For readability - particularly with std::experimental::optional
namespace stdex = std::experimental;

// This is the max number of threads that GlobalWorker will create.
inline const uint32_t MAX_NUM_THREADS = 8;

// The set of satanic keywords...
const std::unordered_set<std::string> KEYWORDS {"devil", "lucifer", "evil", "angel", "dark", "darkness", "satan", "satanic", "hell", "sin", "serpent", "antichrist", "belial", "baphomet", "beelzebub", "mephisto"};

// Another readability help
typedef stdex::optional<size_t> opt_size_t;

// In order: score, str, previous word start pos, previous word index
typedef std::tuple<size_t, std::string, opt_size_t, opt_size_t> result_tuple;

// Removes all the punctuation, capital letters, spaces, etc.
inline void sanitize_text(std::string& str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) {
        return !std::isalpha(static_cast<unsigned char>(c));
    } ), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// GlobalWorker handles all the execution of the BackMask tasks.
class GlobalWorker {
public:
    // Need more info - delete
    GlobalWorker() = delete;
    
    // Creates an instance of a GlobalWorker with the given words stream and bigrams stream.
    GlobalWorker(std::istream& words_stream, std::istream& bigrams_stream);
    
    // Given an input, tries to find back-words for that input.
    void GetBackWords(std::string_view input);
    
    // These are the thread results from the different thread decoding words.
    static std::vector<std::multimap<int, std::pair<std::string, int>>> m_thread_results;
    
    // This is the current thread id that is being spawned.
    static uint64_t m_cur_thread_id;
private:
    // This is a container for all the thread workers, by index.
    std::vector<ThreadWorker> m_thread_workers;
    
    // This is a map of all bigrams.
    std::unordered_multimap<std::string, std::pair<std::string, size_t>> m_bigrams;
    
    // The search tree root from which all dictionary words should come.
    StringViewMaskTrieNode *m_search_trie_root;
    
    // The global results.
    std::multimap<int, std::pair<std::string, int>> m_results;
    
    // The results mutex.
    std::mutex m_results_lock;
    
    // The phrase results.
    std::vector<std::vector<result_tuple>> m_phrase_results;
    
    // Spawns the threads (sometimes just one) which calculate the words.
    void spawnThreads(const std::string_view input, size_t pos, const StringViewMaskTrieNode *cur_node, uint32_t num_threads, struct bit_mask bitmask);
    
    // Assembles phrases at the end, when all words have been calculated.
    void assemblePhrases();
};

#endif
