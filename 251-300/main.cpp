#include <iostream>

#include "problem273.h"
#include "problem274.h"
#include "problem275.h"
#include "problem295.h"


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

    //problem295
    cout << "\n\nproblem295: \n";
    MedianFinder obj239;
    obj239.addNum(-1);
    obj239.addNum(-2);
    cout << "median of (-1, -2): " << obj239.findMedian() << endl;
    obj239.addNum(-3);
    obj239.addNum(-4);
    obj239.addNum(-5);
    cout << "median of (-1, -2, -3, -4, -5): " << obj239.findMedian() << endl;
    return 0;
}