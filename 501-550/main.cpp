#include <iostream>


#include "problem523.h"
#include "problem539.h"

using namespace std;

int main() {
    cout << "Problem 539: \n";
    vector<string> input539{"23:59", "00:00"};
    cout << findMinDifference(input539) << endl << endl;

    cout << "Problem 523: \n";
    vector<int> input523{23, 2, 6, 4, 7};
    cout << "res523 " << checkSubarraySum(input523, 6) << endl;



    return 0;
}