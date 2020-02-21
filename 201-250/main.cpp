#include <iostream>
#include "problem229.h"

using std::end;
using std::cout;

int main() {
//    vector<int> nums229{3, 2};
    vector<int> nums229{1,1,1,3,3,2,2,2};
    vector<int> res =  majorityElement(nums229);

    for (auto i : res)
        cout << i << " ";
    return 0;
}