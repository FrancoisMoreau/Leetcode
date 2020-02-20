#include <iostream>

#include "problem134.h"
#include "problem118.h"
#include "problem119.h"


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


    return 0;
}