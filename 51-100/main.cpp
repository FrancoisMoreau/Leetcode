#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

#include "problem55.h"
#include "problem56.h"
#include "problem57.h"
#include "problem68.h"
#include "problem71.h"
#include "problem76.h"
#include "problem91.h"
#include "problem93.h"

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
    string input91 = "17";

    cout << numDecodings(input91) << endl;

    cout << "\n\nproblem93: \n";
    vector<string> res = restoreIpAddresses("0000");
    for (auto &i : res)
        cout << i << endl;

    cout << "\n\nproblem56: \n";
    vector<vector<int>> input56 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res56 = merge(input56);
    for (auto &i : res56) {
        printf("[%d, %d]\n", i[0], i[1]);
    }

    cout << "\n\nproblem71: \n";
    cout << simplifyPath("/home/") << endl;


    cout << "\n\nproblem57:\n";
    vector<vector<int>> input57{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> input57_rhs = {4, 8};
    insert(input57, input57_rhs);


    return 0;
}