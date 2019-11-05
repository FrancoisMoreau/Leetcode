#include <iostream>
#include "RotatedArraySearch.h"

int main() {
    std::vector<int> vec{4,5,1,2,3};

    RotatedArraySearch rs;
    std::cout << rs.search(vec, 1 ) << "\n";


    return 0;
}