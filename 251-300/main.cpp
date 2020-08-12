#include <iostream>

#include "problem252.h"
#include "problem269.h"
#include "problem273.h"
#include "problem274.h"
#include "problem275.h"
#include "problem287.h"
#include "problem282.h"
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


    cout << "\n\nproblem 287: \n";
    vector<int> input287{1, 3, 4, 2, 1};
    cout << findDuplicate(input287) << endl;

    cout << "\n\nproblem 282: \n";
    vector<string> res282 = addOperators("232", 8);
    for (auto &i : res282)
        cout << i << endl;

    cout << "\n\nproblem269: \n";
//    vector<string> input269{"wrt", "wrf", "er", "ett", "rftt"};
//    vector<string> input269{"ze","yf","xd","wd","vd","ua","tt","sz","rd", "qd","pz","op","nw","mt","ln","ko","jm","il", "ho","gk","fa","ed","dg","ct","bb","ba"};
//    vector<string> input269{"ze","yf","xd","wd","vd","ua","tt","sz","rd", "qd","pz","op","nw","mt","ln","ko","jm","il", "ho","gk","fa","ed","dg","ct","bb","ba"};
    vector<string> input269{"zy", "zx"};
    string res269 = alienOrder(input269);
    cout << res269 << endl;

    cout << "\n\nproblem252: \n";
    vector<vector<int>> input252{{465, 497}, {386, 462}, {354, 380}, {134, 189}, {199, 282}, {18, 104}, {499, 562}, {4, 14}, {111, 129}, {292, 345}};
    cout << canAttendMeetings(input252) << endl;


    return 0;
}