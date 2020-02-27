#include <iostream>

#include "problem273.h"
#include "problem274.h"
#include "problem275.h"


using std::cout;
using std::endl;

int main() {
    //problem 274
    vector<int> nums_274{3, 0, 6, 1, 5};
//    vector<int> nums_274{0};
    cout << hIndex2(nums_274) << endl;

    //problem 275
    vector<int> nums_275{0,1,3,5,6};
    cout << hIndexII(nums_275) << endl;

    //problem273
    cout << numberToWords(123) << endl;
    return 0;
}