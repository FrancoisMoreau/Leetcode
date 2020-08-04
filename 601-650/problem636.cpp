//
// Created by brayden on 2020-05-27.
//

#include "problem636.h"
#include <stack>

using std::vector;
using std::string;
using std::stack;
using std::pair;

// should notice that "start"=> begin of this time, "end" => end of this time
// 70%, 20%
vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<int> stk;
    vector<int> res(n);
    int prev = 0;
    for (int i = 0; i < logs.size(); ++i) {
        auto first = logs[i].find_first_of(':');
        auto last = logs[i].find_last_of(':');
        int cur_id = std::stoi(logs[i].substr(0, first));
        int cur_time = std::stoi(logs[i].substr(last + 1));
        if (logs[i].substr(first + 1, last - first - 1) == "start") {
            if (!stk.empty()) {
                res[stk.top()] += cur_time - prev;
                if (logs[i - 1].find('e') != std::string::npos) --res[stk.top()];
            }
            stk.push(cur_id);
        } else {
            res[stk.top()] += cur_time - prev;
            if (logs[i - 1].find('s') != std::string::npos) ++res[stk.top()];
            stk.pop();
        }
        prev = cur_time;
    }
    return res;
}

// My solution checkes if previois string contains "start"/"end", unnecessary if we add prev + 1 when it's "end"
vector<int> exclusiveTime2(int n, vector<string>& logs) {
    stack<int> stk;
    vector<int> res(n);
    int prev = 0;
    for (auto &log : logs) {
        auto first = log.find_first_of(':');
        auto last = log.find_last_of(':');
        int cur_id = std::stoi(log.substr(0, first));
        int cur_time = std::stoi(log.substr(last + 1));
        if (log[first + 1] == 's') {
            if (!stk.empty()) res[stk.top()] += cur_time - prev;
            stk.push(cur_id);
            prev = cur_time;
        } else {
            res[stk.top()] += cur_time - prev + 1;
            prev = cur_time + 1;
            stk.pop();
        }
    }
    return res;
}

// Solution after 3 month, 03/08/2020
// 85%, 70%
vector<int> exclusiveTime3(int n, vector<string>& logs) {
    stack<int> stk;
    vector<int> res(n, 0);
    int prev = -1;
    for (auto &log : logs) {
        int first = log.find(':');
        int last = log.find_last_of(":");
        int id = stoi(log.substr(0, first));
        int time = stoi(log.substr(last + 1)) - (last - first == 6);
        if (last - first == 6) {
            if (stk.empty())
                res[0] += (time - prev);
            else
                res[stk.top()] += (time - prev);
            stk.push(id);
        } else {
            res[id] += (time - prev);
            stk.pop();
        }
        prev = time;
    }
    return res;
}