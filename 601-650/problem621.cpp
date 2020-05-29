//
// Created by brayden on 2020-05-28.
//

#include "problem621.h"

#include <unordered_map>
#include <queue>
#include <cstdlib>

using std::unordered_map;
using std::vector;
using std::priority_queue;
using std::pair;

// I tried to solve this problem by priority queue, but I found it too complex, my thought was wrong
//  if we can get how many idles we need to arrange A, we will also get number of idles needed to arrange all tasks
// please analyze this kind of problem next time on script paper !

int leastInterval2(vector<char>& tasks, int n) {
    vector<int> counter(26);
    int max = 0;
    int maxcount = 0;
    for (char c : tasks) {
        ++counter[c - 'A'];
        if (max == counter[c - 'A']) {
            ++maxcount;
        } else if (max < counter[c - 'A']) {
            max = counter[c - 'A'];
            maxcount = 1;
        }
    }
    int partcount = max - 1;
    int partLength = n - (maxcount - 1);
    int emptySlots = partcount * partLength;
    int availableTasks = tasks.size() - max * maxcount;
    int idles = std::max(0, emptySlots - availableTasks);
    return tasks.size() + idles;
}
// (c[25] - 1) * (n + 1) + 25 - i  is frame size
// when inserting chars, the frame might be "burst", then tasks.length takes precedence
// when 25 - i > n, the frame is already full at construction, the following is still valid.

int leastInterval(vector<char> &tasks, int n) {
    vector<int> counter(26);
    for (char c : tasks)
        ++counter[c - 'A'];
    std::sort(counter.begin(), counter.end());

    int i = 25;
    while (i >= 0 && counter[i] == counter[25]) --i;
    return std::max(int(tasks.size()), (counter[25] - 1) * (n + 1) + 25 - i);
}

// similar idea
int leastInterval3(vector<char>& tasks, int n) {
    unordered_map<char,int>mp;
    int count = 0;
    for(auto e : tasks)
    {
        mp[e]++;
        count = std::max(count, mp[e]);
    }

    int ans = (count-1)*(n+1);
    for(auto e : mp) if(e.second == count) ans++;
    return std::max((int)tasks.size(), ans);
}