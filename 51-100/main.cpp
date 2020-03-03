#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

#include "problem55.h"
#include "problem68.h"
#include "problem76.h"
#include "problem91.h"

int main() {
    cout << "Problem76: \n";
    string str76_s = "ADOBECODEBANC";
    string str76_t = "ABC";
    cout << minWindow(str76_s, str76_t) << endl;

    cout << "\n\nProblem68: \n";
//    vector<string> input68{"Science","is","what","we","understand","well","enough","to","explain",
//                           "to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> input68{"What","must","be","acknowledgment","shall","be"};
    int num_68 = 16;
    vector<string> res68 = fullJustify(input68, num_68);
    for (auto &i : res68) {
        cout << i << endl;
    }

    cout << "\n\nproblem91: \n";
    string input91 = "110";
    cout << numDecodings(input91) << endl;

    return 0;
}