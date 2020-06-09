//
// Created by brayden on 2020-06-08.
//

#include "problem127.h"

#include <unordered_set>
#include <unordered_map>
#include <queue>

using std::queue;
using std::unordered_set;
using std::unordered_map;
using std::vector;
using std::string;

// My solution based on problem126, 60%, 35%
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordset(wordList.begin(), wordList.end());
    // remenber to erase begin word here, or it will cover the distance map val
    wordset.erase(beginWord);
    if (wordset.find(endWord) == wordset.end()) return 0;
    unordered_map<string, int> dist;
    dist[beginWord] = 1;
    queue<string> q;
    q.push(beginWord);
    while (!q.empty()) {
        if (dist.find(endWord) != dist.end())
            return dist[endWord];
        string cur_word = q.front();
        for (int i = 0; i < cur_word.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                char tmp = cur_word[i];
                cur_word[i] = c;
                if (wordset.find(cur_word) != wordset.end()) {
                    wordset.erase(cur_word);
                    q.push(cur_word);
                    dist[cur_word] = dist[q.front()] + 1;
                }
                cur_word[i] = tmp;
            }
        }
        q.pop();
    }
    return dist[endWord];
}

// Two-end BFS
int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordset(wordList.begin(), wordList.end());
    if (wordset.find(endWord) == wordset.end()) return 0;
    unordered_set<string> beginset, endset;
    unordered_set<string> visited;
    int len = 1, strlen = beginWord.size();
    beginset.insert(beginWord), endset.insert(endWord);
    unordered_set<string> *p_begin = &beginset, *p_end = &endset;
    while (!p_begin->empty() && !p_end->empty()) {
        if (p_begin->size() > p_end->size()) {
            std::swap(p_begin, p_end);
        }
        unordered_set<string> temp;
        for (string word : *p_begin) {
            for (int i = 0; i < strlen; ++i) {
                for (int j = 'a'; j <= 'z'; ++j) {
                    char old = word[i];
                    word[i] = j;
                    if (p_end->find(word) != p_end->end()) {
                        return len + 1;
                    }
                    if (visited.find(word) == visited.end() && wordset.find(word) != wordset.end()) {
                        temp.insert(word);
                        visited.insert(word);
                    }
                    word[i] = old;
                }
            }
        }
        *p_begin = temp;
        ++len;
    }
    return 0;
}