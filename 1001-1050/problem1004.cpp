//
// Created by brayden on 2020-06-02.
//

#include "problem1004.h"

using std::vector;

// My solution, 20%, 10%
// sliding window problem, same idea to problem 76 discussion top vote
int longestOnes(vector<int>& A, int K) {
    int i = 0, j = 0;
    int cur_max = 0;
    while (j < A.size()) {
        if (!A[j]) {
            --K;
            if (K < 0) {
                cur_max = std::max(cur_max, j - i);
                while (A[i]) ++i;
                ++i;
                ++K;
            }
        }
        ++j;
    }
    cur_max = std::max(cur_max, j - i);
    return cur_max;
}

int longestOnes3(vector<int> &A, int K) {
    int i = 0, j;
    int cur_max = 0;
    for (j = 0; j < A.size(); ++j) {
        if (!A[j]) --K;
        while (K < 0) {
            if (A[i] == 0) ++K;
            ++i;
        }
        cur_max = std::max(cur_max, j - i + 1);
    }
    return cur_max;
}

// A simpler one, but same idea, 60%, 10%
// More detailed version: as you can see from the code, j is constantly moving right.
// K here can be considered as the remaining feasible amount of flips, and reflects the
// current range (i.e., from i to j). When K<0, it's not a feasible solution and when K>=0,
// it'll be a feasible solution. If currently range is not yet a feasible solution or better
// than current "memory" frame (i.e., K<0 judgement) , i will try follow up the j and j-i
// (the frame size) remains unchanged, keeping the current maximum size intact.
// Whenever the flip count K of current range (i.e., still i to j) is greater or equals to 0,
// it means we can possibly expand our frame, and that's exactly what the code does.
// (i remains unchanged since it will not goes into K<0 clauses, and j keeps moving when K>=0).
// Eventually, when j comes to the end, the "memory" frame will automatically (by design of course)
// give us the maximum range throughout the array.

int longestOnes2(vector<int> &A, int K) {
    int i = 0, j;
    for (j = 0; j < A.size(); ++j) {
        if (A[j] == 0) --K;
        if (K < 0 && A[i++] == 0) ++K;
    }
    return j - i;
}