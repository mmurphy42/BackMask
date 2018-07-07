#ifndef ThreadWorker_h
#define ThreadWorker_h

#include <string>
#include <thread>
#include <vector>
#include "StringViewMaskTrie.h"

class ThreadWorker {
public:
    // We need a bunch of info to create a worker, so this is not acceptable.
    ThreadWorker() ;
    
    // Constructor for a ThreadWorker. Will pipe this info on to a thread, to begin executing.
    ThreadWorker(const std::string_view input, size_t pos, const StringViewMaskTrieNode *start_node, struct bit_mask bitmask, uint64_t thread_id);
    
    // The function to calculate strings from the bitmasks and positions provided.
    void CalcStrings(const std::string_view input, size_t pos, const StringViewMaskTrieNode *cur_node, struct bit_mask bitmask, uint64_t thread_id);
    
    // Waits to finish thread execution.
    void WaitToFinish();
    
private:
    // The single thread assigned to this worker.
    std::thread m_thread;
};

#endif
