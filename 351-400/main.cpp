#include <iostream>

#include "problem352.h"
#include "problem378.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
    cout << "problem378: \n";
    vector<vector<int>> input378{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int res378 = kthSmallest(input378, 8);
    cout << res378 << endl;

    cout << "\n\nproblem352\n";
    SummaryRanges obj352 = SummaryRanges();
    obj352.addNum(1);
    print(obj352);
    obj352.addNum(3);
    print(obj352);
    obj352.addNum(7);
    print(obj352);
    obj352.addNum(2);
    print(obj352);
    obj352.addNum(6);
    print(obj352);
    return 0;
}