#include <iostream>


#include "problem217.h"
#include "problem218.h"
#include "problem219.h"
#include "problem220.h"
#include "problem229.h"
#include "problem243.h"
#include "problem244.h"
#include "problem245.h"


using std::endl;
using std::cout;

int main() {
    cout << "\n\nproblem 229: \n";
//    vector<int> nums229{3, 2};
    vector<int> nums229{1,1,1,3,3,2,2,2};
    vector<int> res =  majorityElement(nums229);
    for (auto i : res)
        cout << i << " ";

    cout << "\n\nproblem 243: \n";
    //problem 243
    vector<string> words{"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "coding", word2 = "practice";
    cout << shortestDistance2(words, word1, word2) << endl;

    //problem244
    cout << "\n\nproblem 244: \n";
    WordDistance myword_dis(words);
    cout << myword_dis.shortest("coding", "practice") << endl;

    //prblem245
    cout << "\n\nproblem 245: \n";

    cout << shortestWordDistanceIII(words, word1, word2) << endl;

    //problem217
    cout << "\n\nproblem 217: \n";
    vector<int> nums217{1, 1, 2, 3};
    cout << containsDuplicate(nums217) << endl;

    //problem218
    cout << "\n\nproblem218: \n";
//    vector<vector<int>> input218{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> input218{{2, 4, 7}, {2, 4, 5}, {2, 4, 6}};
    vector<vector<int>> res218 = getSkyline(input218);
    for (auto &i : res218) {
        printf("[%d %d]\n", i[0], i[1]);
    }

    //problem220
    cout << "\n\nproblem 220: \n";
    vector<int> nums220{1,2,3,1};

    return 0;
}