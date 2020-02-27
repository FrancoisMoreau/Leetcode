#include <iostream>
#include <vector>
#include <string>

#include "problem3.h"
#include "problem5.h"
#include "problem20.h"
#include "problem22.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
    //problem3
    cout << "problem3: \n";
    string str3 = "abba";
    cout << lengthOfLongestSubstring(str3) << endl;

    cout << "\n\nproblem5: \n";
    string str5 = "babad";
    cout << longestPalindrome(str5) << endl;

    cout << "\n\nproblem20: \n";
    string str20 = "()";
    cout << isValid(str20) << endl;

    cout << "\n\nproblem22: \n";
    vector<string> res22 = generateParenthesis(3);
    for (auto &i : res22) {
        cout << i << endl;
    }
    return 0;
}