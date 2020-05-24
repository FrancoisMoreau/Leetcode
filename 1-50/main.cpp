#include <iostream>
#include <vector>
#include <string>

#include "problem3.h"
#include "problem5.h"
#include "problem17.h"
#include "problem20.h"
#include "problem22.h"
#include "problem29.h"
#include "problem50.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
    //problem3
    cout << "problem3: \n";
    string str3 = "abba";
    cout << lengthOfLongestSubstring3(str3) << endl;

    cout << "\n\nproblem5: \n";
    string str5 = "babad";
    cout << longestPalindrome(str5) << endl;

    cout << "\n\nproblem17: \n";
    string str17 = "23";

    vector<string> res17 = letterCombinations(str17);
    for (auto &i : res17) {
        cout << i << endl;
    }


    cout << "\n\nproblem20: \n";
    string str20 = "()";
    cout << isValid(str20) << endl;

    cout << "\n\nproblem22: \n";
    vector<string> res22 = generateParenthesis(3);
    for (auto &i : res22) {
        cout << i << endl;
    }

    cout << "\n\nproblem50: \n";
    cout << myPow(2.1, 3) << endl;

    cout << "\n\nproblem29: \n";
    cout << divide2(-2147483648, -1) << endl;

    return 0;
}