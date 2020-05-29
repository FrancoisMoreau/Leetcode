#include <iostream>

#include "problem721.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "problem721: \n";
    vector<vector<string>> input721 = {{"David","David0@m.co","David1@m.co"},
                                       {"David","David3@m.co","David4@m.co"},
                                       {"David","David4@m.co","David5@m.co"},
                                       {"David","David2@m.co","David3@m.co"},
                                       {"David","David1@m.co","David2@m.co"}};
    vector<vector<string>> res721 = accountsMerge(input721);
    for (auto &i : res721) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}