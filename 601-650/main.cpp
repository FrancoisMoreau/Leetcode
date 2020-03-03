#include <iostream>

#include "problem609.h"

using namespace std;
int main() {
    vector<string> input609{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    vector<vector<string>> res609 = findDuplicate(input609);
    for (auto &i : res609) {
        for (auto &j : i)
            cout << j << endl;
    }
    return 0;
}