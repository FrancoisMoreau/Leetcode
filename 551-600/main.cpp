#include <iostream>

#include "problem572.h"

using std::cout;
using std::endl;

int main() {
    TreeNode root(3), lhs1(4), rhs1(5), lhs2(1), lhs2rhs(2);
    root.left = &lhs1;
    root.right = &rhs1;
    lhs1.left = &lhs2;
    lhs1.right = &lhs2rhs;
    cout << "problem 572\n";
    cout << isSubtree(&root, &lhs1) << endl;

    return 0;
}