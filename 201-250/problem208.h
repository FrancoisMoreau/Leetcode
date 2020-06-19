//
// Created by brayden on 2020-06-16.
//

#ifndef INC_201_250_PROBLEM208_H
#define INC_201_250_PROBLEM208_H

#include <string>
#include <vector>

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode) {

    }

    ~Trie() {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        auto node = root;
        for (char c : word) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        auto node = root;
        for (char c : word) {
            if (!node->next[c - 'a'])
                return false;
            node = node->next[c - 'a'];
        }
        return node->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        auto node = root;
        for (char c : prefix) {
            if (!node->next[c - 'a'])
                return false;
            node = node->next[c - 'a'];
        }
        return true;
    }

private:
    struct TrieNode {
        bool is_word;
        std::vector<TrieNode *> next = std::vector<TrieNode *>(26, nullptr);
        ~TrieNode() {
            for (auto p : next)
                delete p;
        }
    };
    TrieNode *root;
};

#endif //INC_201_250_PROBLEM208_H
