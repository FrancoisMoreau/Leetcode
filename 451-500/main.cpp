#include <iostream>
#include "problem468.h"
#include "problem490.h"
#include "problem498.h"
#include <vector>
#include <string>

using namespace std;

int main() {
    cout << validIPAddress("1.1.1.") << endl;

    vector<vector<int>> input498{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res498 = findDiagonalOrder(input498);
    for (int i : res498)
        cout << i << " ";
    cout << endl;



    cout << "\n\nproblem490: \n";
    vector<vector<int>> input490_1{{0,0,1,0,0},
                                   {0,0,0,0,0},
                                   {0,0,0,1,0},
                                   {1,1,0,1,1},
                                   {0,0,0,0,0}};
    vector<int> input490_2{0, 4};
    vector<int> input490_3{3, 2};
    cout << hasPath(input490_1, input490_2, input490_3) << endl;

    return 0;
}