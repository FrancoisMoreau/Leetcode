#include <iostream>

#include "problem134.h"
#include "problem118.h"
#include "problem119.h"
#include "problem121.h"
#include "problem123.h"


using std::cout;
using std::endl;


int main() {
    //problem134
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    cout << canCompleteCircuit2(gas, cost) << endl;

    //problem 118
    vector<vector<int>> triangle = generate(5);
    for (auto &i : triangle) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }

    //problem119
    vector<int> indexrow = getRow(4);
    for (auto &i : indexrow)
        cout << i << " ";

    //problem121
    cout << "\n\nproblem121: \n";
    // std::vector<int> nums{7, 1, 5, 3, 6, 4};
    std::vector<int> nums121{7, 6, 4, 3, 1};
    cout << maxProfit2(nums121) << endl;


    //problem123
    cout << "\n\nproblem123: \n";
    // std::vector<int> nums{7, 1, 5, 3, 6, 4};
    std::vector<int> nums123{3,3,5,0,0,3,1,4};
    cout << maxProfitIII3(nums123) << endl;

    return 0;
}