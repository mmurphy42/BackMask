#ifndef StringViewMaskTrie_h
#define StringViewMaskTrie_h

#include <stdint.h>
#include <vector>
#include <string>
#include <array>
#include <memory>
#include <iostream>
#include <experimental/optional>
#include <utility>

// The number of letters in the English alphabet.
inline const uint8_t NUM_LETTERS = 26;

// Converts a character to a number representation (0 to NUM_LETTERS-1)
inline uint8_t charToInt(char c) {
    return c - 'a';
}

// This class is responsible for traversing through the English dictionary provided.
class StringViewMaskTrieNode {
public:
    // Constructs a blank node with null children.
    StringViewMaskTrieNode() : m_full_word(), m_children{nullptr} {}
    
    // Inserts a string node-by-node, and marks that string as a valid word.
    void InsertString(StringViewMaskTrieNode *root, const std::string_view str);
    
    // Gets next node, by letter.
    StringViewMaskTrieNode* GetNext(const std::string_view str, size_t pos) const;
    
    // Returns whether this node is a word.
    bool IsWord() const;
    
    // Gets the word, if one exists, for this node.
    const std::string& GetWord() const;
    
    // Returns true if there are children beneath this node.
    bool HasChildren() const;
    
private:
    // The full word for this node, if applicable.
    std::string m_full_word;
    
    // The children for this node.
    std::array<StringViewMaskTrieNode*, NUM_LETTERS> m_children;
};

#endif
