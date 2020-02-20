//
// Created by brayden on 2020-02-20.
//
#include "problem134.h"

//O(N^2), brute-force

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    for (int i = 0; i < n; ++i) {
        gas[i] -= cost[i];
    }
    for (int i = 0; i < gas.size(); ++i) {
        if (gas[i] < 0) continue;
        int gas_left = gas[i];
        for (int j = 1; j < n; ++j) {
            gas_left += gas[(i + j) % n];
            if (gas_left < 0) break;
        }
        if (gas_left >= 0) return i;
    }
    return -1;
}

//O(N)
//1. if sum of gas is bigger than sum of cost, then there must be a solution
//2. the tank should never be negative

int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
    int total = 0;
    int tank = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i) {
        tank += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (tank < 0) {
            tank = 0;
            start = i + 1;
        }
    }
    return (total >= 0)? start : -1;
}