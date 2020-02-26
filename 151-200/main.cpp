#include <iostream>
#include "problem164.h"
#include "problem169.h"
#include "problem188.h"

using std::cout;
using std::endl;


int main() {
    //problem 169
    vector<int> nums169{2,2,1,1,1,2,2};
    cout << majorityElement2(nums169) << endl;

    //problem 188
    cout << "\n\nProblem188: " << endl;
    vector<int> nums188{3, 2, 6, 5, 0, 3};
    cout << maxProfit_ktran(2, nums188) << endl;

    //problem 164
    vector<int> nums164{3, 6, 9, 1};
    cout << maximumGap(nums164) << endl;

    return 0;
}