//
// Created by brayden on 2020-08-07.
//

#include "problem824.h"

#include <sstream>
using std::string;

// 100%, 85%
string toGoatLatin(string S) {
    std::stringstream ss(S);
    string res, word, tail = "a";
    while (ss >> word) {
        if (word.find_first_of("aeiouAEIOU") == 0) {
            word += "ma";
        } else {
            word = word.substr(1) + word[0] + "ma";
        }
        res += word + tail + " ";
        tail += "a";
    }
    res.pop_back();
    return res;
}