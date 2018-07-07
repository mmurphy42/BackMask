#include <utility>
#include "StringViewMaskTrie.h"

void StringViewMaskTrieNode::InsertString(StringViewMaskTrieNode *root, const std::string_view str)
{
    auto *cur_pointer = root;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        uint8_t index = charToInt(str[i]);
        if (!(cur_pointer->m_children[index] != nullptr))
            cur_pointer->m_children[index] = new StringViewMaskTrieNode();
        
        cur_pointer = cur_pointer->m_children[index];
    }
    
    // Last node is a full word.
    cur_pointer->m_full_word = std::string(str);
}

StringViewMaskTrieNode* StringViewMaskTrieNode::GetNext(const std::string_view str, size_t pos) const
{
    return this->m_children[charToInt(str[pos])];
}

const std::string& StringViewMaskTrieNode::GetWord() const
{
    return m_full_word;
}

bool StringViewMaskTrieNode::IsWord() const
{
    return !(m_full_word.empty());
}

bool StringViewMaskTrieNode::HasChildren() const
{
    return !(this->m_children.empty());
}