#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <thread>
#include <algorithm>
#include <mutex>
#include <math.h> 
#include <sstream>
#include <chrono>
#include "GlobalWorker.h"
#include "ThreadWorker.h"

inline const std::string INPUT_DEFAULT = "Play Chess Online on the #1 Chess Site - Play with over 20 million members";

int main(int argc, const char * argv[]) {
    
    // Makes the code below much more readable.
    namespace stdc = std::chrono;
    
    std::ifstream inFile_words, inFile_bigrams;
    inFile_words.open("satan_1grams.txt");
    if (!inFile_words) {
        std::cout << "Unable to open words file";
        exit(1);
    }
    inFile_bigrams.open("satan_2grams.txt");
    if (!inFile_bigrams) {
        std::cout << "Unable to open 2grams file";
        exit(1);
    }
    
    // Begin the clock!
    stdc::time_point<stdc::steady_clock> start = stdc::steady_clock::now();
    
    // Initialize the global worker, and start reading in the unigrams and bigrams.
    auto global_worker = GlobalWorker(inFile_words, inFile_bigrams);

    // Default string - otherwise take the first argument as input.
    std::string input = (argc > 1) 
        ? argv[1] 
        : INPUT_DEFAULT;
    
    std::cout << "Input: " << input << std::endl;
    sanitize_text(input);
    global_worker.GetBackWords(input);

    stdc::time_point<stdc::steady_clock> end = stdc::steady_clock::now();
    stdc::milliseconds diff = stdc::duration_cast<stdc::milliseconds>(end - start);
    std::cout << diff.count() << "ms" << std::endl;
    return 0;
}
