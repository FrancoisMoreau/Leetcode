//
// Created by brayden on 2020-05-14.
//

#include "problem218.h"
#include <queue>
#include <set>

using std::set;
using std::vector;
using std::priority_queue;
using std::pair;

auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return lhs.first > rhs.first;
};

// couldn't pass edge case
/*
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // Take care of priority queue initializaition!!!
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> end_pq(cmp);
    std::multiset<int> h_pq;
    int cur_h = 0, idx = 0;
    vector<vector<int>> res;
    while (!end_pq.empty() || idx < buildings.size()) {
        while (idx < buildings.size() && (end_pq.empty() || buildings[idx][0] <= end_pq.top().first)) {
            if (buildings[idx][2] > cur_h) {
                if (idx == buildings.size() - 1 || buildings[idx][0] < buildings[idx + 1][0] || buildings[idx][2] > buildings[idx + 1][2])
                    res.push_back({buildings[idx][0], buildings[idx][2]});
                cur_h = buildings[idx][2];
            }
            end_pq.push({buildings[idx][1], buildings[idx][2]});
            h_pq.insert(buildings[idx][2]);
            ++idx;
        }
        h_pq.erase(h_pq.lower_bound(end_pq.top().second));
        int next_h = h_pq.empty()? 0 : *h_pq.crbegin();
        if (next_h < cur_h)
            res.push_back({end_pq.top().first, next_h});
        cur_h = next_h;
        end_pq.pop();
    }
    return res;
}
 */

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    pair<int,int> curr({0,0});
    vector<vector<int>> result;
    std::multiset<pair<int,int>> seq;
    for(auto p:buildings){
        seq.emplace(std::make_pair(p[0],-p[2]));
        seq.emplace(std::make_pair(p[1],p[2]));
    }
    std::multiset<int> height({0});
    for(auto p:seq){
        if(p.second<0)height.emplace(-p.second);
        else height.erase(height.find(p.second));
        if(*height.rbegin()!=curr.second){
            curr.first=p.first;
            curr.second=*height.rbegin();
            result.push_back({curr.first, curr.second});
        }
    }
    return result;
}