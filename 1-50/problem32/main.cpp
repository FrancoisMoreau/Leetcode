#include <iostream>
#include "LongestValidParentheses.h"

using std::cout;
using std::endl;

int main() {
    LongestValidParentheses lvp;
    std::string in(")()())");
    cout <<  lvp.longestValidParentheses(in) << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}