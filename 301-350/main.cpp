#include <iostream>

#include "problem301.h"
#include "problem309.h"
#include "problem336.h"
#include "problem315.h"
#include "problem316.h"
#include "problem329.h"
#include "problem347.h"

using std::cout;
using std::endl;

int main() {
    //problem309
    cout << "problem309: \n";
    vector<int> nums_309{2,1,4,5,2,9,7};
    cout << maxProfit_cooldown(nums_309) << endl;

    cout << "\n\nproblem 336:\n";
    vector<string> input336{"abcd","dcba","lls","s","sssll"};
    vector<vector<int>> res336 =  palindromePairs(input336);
    for (auto &i : res336) {
        cout << "[" << i[0] << ", " << i[1] << "]\n";
    }


    cout << "\n\nproblem 316: \n";
    cout << removeDuplicateLetters2("bddbccd") << "\n\n";

    printf("subset 0: \n");
    cout << maximumZeroSubsequenceLength({2, 9, 3, -5, 7}) << endl;
    cout << subsetsum0({4, -2, -3, -6, 2, 9}) << endl;

    cout << "\n\n problem 347: \n";
    vector<int> input_347{1,1,1,2,2,3, 4, 4, 4, 4};
    vector<int> res = topKFrequent(input_347, 2);
    for (auto i : res)
        printf("%d, ", i);

    cout << "\n\nproblem315: \n";
    vector<int> input315{1, 9, 7, 8, 5};
    vector<int> res315 = countSmaller4(input315);
    for (auto i : res315)
        printf("%d ", i);


    cout << "\n\n\nproblem329: \n";
    vector<vector<int>> input329{{1, 2}};
    cout << longestIncreasingPath(input329) << endl;

    cout << "\n\nproblem301: \n";
    vector<string> res301 = removeInvalidParentheses("()())()");
    for (auto &i : res301)
        cout << i << endl;


    return 0;
}