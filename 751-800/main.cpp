#include <iostream>

#include "problem767.h"
#include "problem785.h"

using std::string;
using std::cout;
using std::endl;
using namespace std;

int main() {
    cout << "problem767: \n";
    string res = reorganizeString("aab");
    cout << res << endl;

    cout << "\n\nproblem785: \n";
    vector<vector<int>> input785{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Bipartite? " << isBipartite(input785) << endl;


    return 0;
}