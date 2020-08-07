#include <iostream>
#include <vector>
#include "problem689.h"

using namespace std;

int main() {
    std::cout << "problem 689" << std::endl;

    vector<int> input689{7,13,20,19,19,2,10,1,1,19};
    vector<int> res689 = maxSumOfThreeSubarrays(input689, 3);
    for (int i : res689)
        cout << i << ", ";
    cout <<endl;

    return 0;
}