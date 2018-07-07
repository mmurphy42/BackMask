#include "ThreadWorker.h"
#include "GlobalWorker.h"
#include <limits>
#include <utility>

void ThreadWorker::CalcStrings(const std::string_view input, size_t pos, const StringViewMaskTrieNode *cur_node, struct bit_mask bitmask, uint64_t thread_id) {
    size_t length = input.length();
    // Try recursing with a "0".
    if (pos + 1 < length) {
        CalcStrings(input, pos + 1, cur_node, bitmask, thread_id);
    }

    // Now try a "1" at this position.
    auto next_node = cur_node->GetNext(input, (length - pos - 1));
    
    // Do we actually have a node here?
    if (next_node) {
        // Check whether this is actually a word.
        auto bitmask_new = AddOneBit(pos, bitmask, length);
        if (next_node->IsWord()) {
            auto [start_pos, end_pos] = GetBitEdges(length, bitmask_new);
            GlobalWorker::m_thread_results[thread_id].insert(
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
            if (pos + 1 < length) {
                CalcStrings(input, pos + 1, next_node, bitmask_new, thread_id);
            }
        }
    }
}

ThreadWorker::ThreadWorker(
    const std::string_view input, 
    size_t pos, 
    const StringViewMaskTrieNode *start_node, 
    struct bit_mask bitmask, 
    uint64_t thread_id
)
{
    // Immediately make a thread and start executing.
    m_thread = std::thread(
        &ThreadWorker::CalcStrings, 
        this, 
        input, 
        pos, 
        start_node, 
        bitmask, 
        thread_id
    );
}

void ThreadWorker::WaitToFinish() {
    m_thread.join();
}
