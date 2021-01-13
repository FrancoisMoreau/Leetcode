#include <iostream>
#include "problem410.h"
#include "problem419.h"


using std::cout;
using std::endl;
using std::vector;

int quickpartition(vector<int> &arr, int lo, int hi) {
    int i = lo, j = hi + 1;
    while (true) {
        while (arr[++i] < arr[lo]) {
            if (i >= hi) break;
        }
        while (arr[--j] > arr[lo]) {
            if (j <= i) break;
        }
        if (i >= j) break;
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[lo], arr[j]);
    return j;

}

void quicksort(vector<int> &arr, int lo, int hi) {
    if (lo >= hi) return;
    int mid = quickpartition(arr, lo, hi);
    quicksort(arr, lo, mid - 1);
    quicksort(arr, mid + 1, hi);
}

void quicksort(vector<int> &arr) {
    quicksort(arr, 0, arr.size() - 1);
}

int main() {
    printf("\nproblem410: \n");
    vector<int> input410{7, 2, 5, 10, 8};
    cout << splitArray(input410, 2) << endl;

    cout << "\n\nproblem419: \n";
    vector<vector<char>> input419{{'X', '.', 'X'}, {'X', '.', 'X'}};
    cout << countBattleships(input419) << endl;

    vector<int> quick_input{40, 100, 1, 5, 25, 10};
    quicksort(quick_input);
    for (int i : quick_input)
        cout << i << " ";



    return 0;
}