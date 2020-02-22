#include <iostream>


#include "problem217.h"
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


    return 0;
}