#include <iostream>

#include "problem973.h"

using std::vector;

int main() {
    vector<vector<int>> input_973{{3, 3}, {5, -1}, {-2, 4}};
    auto res = kClosest2(input_973, 2);
    for (auto &i : res) {
        printf("{%d, %d}\n", i[0], i[1]);
    }

    return 0;
}