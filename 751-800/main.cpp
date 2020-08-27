#include <iostream>

#include "problem766.h"
#include "problem767.h"
#include "problem785.h"

using std::string;
using std::cout;
using std::endl;
using namespace std;

int main() {
    cout << "problem766: \n";
    vector<vector<int>> input766{{11, 74, 0, 93}, {40, 11, 74, 7}};
    cout << isToeplitzMatrix(input766) << endl;



    cout << "problem767: \n";
    string res = reorganizeString("aab");
    cout << res << endl;

    cout << "\n\nproblem785: \n";
    vector<vector<int>> input785{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Bipartite? " << isBipartite(input785) << endl;


    return 0;
}