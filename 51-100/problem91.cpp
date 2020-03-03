//
// Created by brayden on 2020-02-28.
//

#include "problem91.h"
#include <vector>

using std::vector;

// My original thought was wrong
// we should implement dynamic programming here


int numDecodings(string s) {
    if (s[0] == '0') return 0;
    vector<int> max(s.size(), 1);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (s[i - 1] == '0' || s[i - 1] > '2') return 0;
            if (i > 1 && max[i - 1] != max[i - 2]) max[i] = max[i - 2];
            else max[i] = max[i - 1];
        } else if (s[i] < '7') {
            if (s[i - 1] < '3' && s[i - 1] != '0')
                max[i] = max[i - 1] + 1;
            else max[i] = max[i - 1];
        } else {
            if (s[i - 1] < '2' && s[i - 1] != '0')
                max[i] = max[i - 1] + 1;
            else max[i] = max[i - 1];
        }
    }
    return max[s.size() - 1];
}