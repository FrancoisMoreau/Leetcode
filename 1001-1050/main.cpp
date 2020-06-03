#include <iostream>

#include "problem1004.h"

using namespace std;

int main() {
    cout << "problem 1004: \n";
    vector<int> input1004 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << longestOnes(input1004, 3) << endl;
    return 0;
}