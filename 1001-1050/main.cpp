#include <iostream>

#include "problem1004.h"
#include "problem1027.h"

using namespace std;

int main() {
    cout << "problem 1004: \n";
    vector<int> input1004 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << longestOnes(input1004, 3) << endl;

    cout << "problem 1027: \n";
//    vector<int> input1027{3, 6, 9, 12};
    vector<int> input1027{22,8,57,41,36,46,42,28,42,14,9,43,27,51,0,0,38,50,31,60,29,31,20,23,37,53,27,1,47,42,28,31,10,35,39,12,15,6,35,31,45,21,30,19,5,5,4,18,38,51,10,7,20,38,28,53,15,55,60,56,43,48,34,53,54,55,14,9,56,52};
    cout << longestArithSeqLength(input1027) << endl;
    return 0;
}