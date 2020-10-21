#include <iostream>
#include <deque>
#include <unordered_map>

#include "problem766.h"
#include "problem767.h"
#include "problem785.h"
#include "problem787.h"

using std::string;
using std::cout;
using std::endl;
using namespace std;

void test() {
    unsigned  char ch  = 0;
    int count = 0;
    while (++ch <= 255) {
        count++;
    }
    printf("%d", count);
}

// akuna capital c++
// subarray maxmin
int subarray_maxmin(vector<int> &arr, int k) {
    std::deque<int> dq;
    int n = arr.size();
    vector<int> minarr;
    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && i - dq.front() >= k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] > arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i - k >= -1) minarr.push_back(arr[dq.front()]);
    }
    for (int i : minarr)
        cout << i << "\n";
    return *(std::max_element(minarr.begin(), minarr.end()));
}

// akuna capital c++
// group options
int suboptions(int n, int k, vector<vector<int>> &mem) {
    if (n < k) return 0;
    if (n == k) return 1;
    if (mem[n][k] != -1) return mem[n][k];
    int cur = 0;
    for (int i = 1; i <= k; ++i) {
        cur += suboptions(n - k, i, mem);
    }
    mem[n][k] = cur;
    return cur;
}

int countOptions(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return suboptions(n, k, dp);
}

int countOp2(int n, int k) {
    if (n < k) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= n; ++i) dp[i][1] = 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j - 1];
            if (i >= 2 * j) dp[i][j] += dp[i - j][j];
        }
    }
    return dp[n][k];

}


bool dfs(unordered_map<string, vector<int>> &dict, vector<vector<string>> &tickets, vector<string> &res, vector<bool> &used) {
    if (res.size() == tickets.size() + 1) return true;
    for (int i : dict[res.back()]) {
        if (!used[i]) {
            string next = tickets[i][0] == res.back() ? tickets[i][1] : tickets[i][0];
            res.push_back(next);
            used[i] = true;
            if (dfs(dict, tickets, res, used))
                return true;
            res.pop_back();
            used[i] = false;
        }
    }
    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<int>> dict;
    for (int i = 0; i < tickets.size(); ++i) {
        dict[tickets[i][0]].push_back(i);
        dict[tickets[i][1]].push_back(i);
    }
    vector<bool> used(tickets.size());
    vector<string> res{tickets[0][0]};
    dfs(dict, tickets, res, used);
    return res;
}


int main() {
    cout << "problem766: \n";
    vector<vector<int>> input766{{11, 74, 0, 93}, {40, 11, 74, 7}};
    cout << isToeplitzMatrix(input766) << endl;


    cout << "problem767: \n";
    string res = reorganizeString("aab");
    cout << res << endl;

    cout << "\n\nproblem785: \n";
    vector<vector<int>> input785{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Bipartite? " << isBipartite(input785) << endl;


    cout << "\n\nakuna capital minmax: \n";
    vector<int> input_akuna1 = {1, 4, 3, 10, 5};
    cout << subarray_maxmin(input_akuna1, 2) << endl;

    cout << "\n\nakuna captal countoptions: \n";
    cout << countOptions(150, 101) << endl;

    cout << "\n\n akuna2 : \n";
    cout << countOp2(150, 101) << endl;


    vector<vector<string>> input_circlue{{"5", "3"}, {"3", "4"}, {"4", "2"}, {"2", "3"}, {"3", "5"}};
    vector<string> res_circle = findItinerary(input_circlue);
    for (auto &i : res_circle) {
        cout << i << " - ";
    }

    return 0;
}