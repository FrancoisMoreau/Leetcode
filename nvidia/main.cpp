#include <iostream>
#include "SparseVec.h"
#include "random_bit.h"

using namespace std;

int main() {
    // Sparse vector class
    cout << "sparse vector: \n";
    SparseVec sp_vec1{0, 0, 1, 0, 0, 0, 5, 6}, sp_vec2{1, 0, 4, 0, 0, 0, 1, 0};
    int sp_res = sp_vec1 * sp_vec2;
    cout << sp_res << endl;
    cout << "\n\nrandom set bit: \n";
    int prev_set = 1000;
    cout << prev_set << " <=> " << random_set_bit(prev_set) << endl;



    std::cout << "Hello, World!" << std::endl;
    return 0;
}