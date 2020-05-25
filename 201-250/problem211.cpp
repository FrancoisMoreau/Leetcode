//
// Created by brayden on 2020-05-24.
//

#include "problem211.h"

using std::string;

//bool WordDictionary::search(std::string word) {
//    std::set<string> *pt;
//    if (word[0] == '.') {
//        pt = &reversed;
//        std::reverse(word.begin(), word.end());
//    }
//    else pt = &wordset;
//    auto dis = std::distance(word.begin(), std::find(word.begin(), word.end(), '.'));
//    string pref_word = word.substr(0, dis);
//    for (auto pos =pt->lower_bound(pref_word); pos != pt->end(); ++pos) {
//        if (pos->substr(0, dis) != pref_word) return false;
//        if (word.size() == pos->size())
//            return true;
//    }
//    return false;
//}

// using hash
class WordDictionary2 {
public:
    WordDictionary() {}

    void addWord(string word) {
        words[word.size()].push_back(word);
    }

    bool search(string word) {
        for(auto s: words[word.size()]) if(isEqual(s, word)) return true;
        return false;
    }

private:
    unordered_map<int, vector<string>>words;

    bool isEqual(string a, string b){
        for(int i = 0; i < a.size(); i++){
            if(b[i] == '.') continue;
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};