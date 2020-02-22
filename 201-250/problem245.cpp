

#include "problem245.h"

int shortestWordDistanceIII(vector<string>& words, string word1, string word2) {
    int min_dis = words.size();
    int lastIndex = -1;
    for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word1 || words[i] == word2) {
            if (lastIndex != -1 && (words[i] != words[lastIndex] || word1 == word2))
                min_dis = std::min(min_dis, i - lastIndex);
            lastIndex = i;
        }
    }
    return min_dis;
}