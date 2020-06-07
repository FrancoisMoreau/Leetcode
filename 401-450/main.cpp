#include <iostream>
#include "problem410.h"
#include "problem419.h"


using std::cout;
using std::endl;
using std::vector;

int main() {
    printf("\nproblem410: \n");
    vector<int> input410{7, 2, 5, 10, 8};
    cout << splitArray(input410, 2) << endl;

    cout << "\n\nproblem419: \n";
    vector<vector<char>> input419{{'X', '.', 'X'}, {'X', '.', 'X'}};
    cout << countBattleships(input419) << endl;



    return 0;
}