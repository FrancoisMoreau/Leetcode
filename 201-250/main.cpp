#include <iostream>

#include "problem209.h"
#include "problem211.h"
#include "problem211.h"
#include "problem217.h"
#include "problem218.h"
#include "problem219.h"
#include "problem220.h"
#include "problem229.h"
#include "problem238.h"
#include "problem239.h"
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

    //problem239
    cout << "\n\nproblem239: \n";
    vector<int> input239{1,3,-1,-3,5,3,6,7};
    vector<int> res239 = maxSlidingWindow(input239, 3);
    for (auto i : res239)
        printf("%d  ", i);

    //problem209
    vector<int> input209{2, 3, 1, 2, 4, 3};
    cout << "\n\nproblem 209: \n";
    cout << minSubArrayLen(7, input209) << endl;

    //problem211
    cout << "\n\nproblem211: \n";
    WordDictionary obj211 ;
    obj211.addWord("bad");
    obj211.addWord("dad");
    obj211.addWord("mad");
    printf("pad: %d\n", obj211.search("pad"));
    printf("bad: %d\n", obj211.search("bad"));
    printf(".ad: %d\n", obj211.search(".ad"));
    printf("b..: %d\n", obj211.search("b.."));

    //problem238
    cout << "\n\nproblem238: \n";
    vector<int> input238{1, 2, 3, 4};
    vector<int> res238 = productExceptSelf(input238);
    for (auto i : res238)
        cout << i << " ";


    return 0;
}