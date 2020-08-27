#include <iostream>
#include <vector>
#include <string>
#include "problem825.h"
#include "problem839.h"

using namespace std;

int main() {
    cout << "problem825: \n";
//    vector<int> input825{118,14,7,63,103};
    vector<int> input825{8,85,24,85,69};
    cout << numFriendRequests(input825) << endl;

    cout << "problem839: \n";
    vector<string> input839{"tars","rats","arts","star"};
    cout << numSimilarGroups(input839) << endl;

    return 0;
}