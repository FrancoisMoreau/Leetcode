//
// Created by brayden on 2020-05-24.
//

#ifndef INC_201_250_PROBLEM211_H
#define INC_201_250_PROBLEM211_H

#include <string>
#include <algorithm>
#include <set>

struct TrieNode {
    TrieNode *next[26];
    bool is_leaf = false;
    ~TrieNode() {
        for (auto &i : next)
            delete(i);
    }
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() = default;

    /** Adds a word into the data structure. */
    void addWord(std::string word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->next[c  - 'a'])
                node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->is_leaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(std::string word) {
        return search(word.c_str(), root);
    }

private:
    bool search(const char *word, TrieNode *node) {
        for (int i = 0; word[i] && node; ++i) {
            if (word[i] != '.')
                node = node->next[word[i] - 'a'];
            else {
                TrieNode *tmp = node;
                for (int j = 0; j < 26; ++j) {
                    node = tmp->next[j];
                    if (search(word + i + 1, node))
                        return true;
                }
            }
        }
        return node && node->is_leaf;
    }
    TrieNode *root = new TrieNode();
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
#endif //INC_201_250_PROBLEM211_H
