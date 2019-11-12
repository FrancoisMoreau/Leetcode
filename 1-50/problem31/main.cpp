#include <iostream>
#include <vector>


void nextPermutation(std::vector<int> &nums) {
//    if (nums.size() == 1)
//        return;
    int biggest = nums.back();
    std::vector<int> tail;
    auto r_iter = nums.rbegin();
    for (; r_iter != nums.rend(); ++r_iter) {
        tail.push_back(*r_iter);
        if (biggest > *r_iter) break;
        else biggest = *r_iter;
    }
    if (r_iter == nums.rend() || *(r_iter - 1) > biggest) {
        std::sort(nums.begin(), nums.end());
        return;
    }
    std::sort(tail.begin(), tail.end());
    auto it_first = std::upper_bound(tail.begin(), tail.end(), *r_iter);
    std::swap(*it_first, *tail.begin());
    std::sort(tail.begin() + 1, tail.end());
    std::copy(tail.begin(), tail.end(), r_iter.base() - 1);
}

void nextPermutation2(std::vector<int> &nums) {
    auto biggest = nums.back();
    auto r_iter = nums.rbegin();
    for (; r_iter != nums.rend(); ++r_iter) {
        if (biggest > *r_iter) break;
        else biggest = *r_iter;
    }
    if (r_iter == nums.rend() || *(r_iter - 1) > biggest) {
//        std::sort(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.end());
        return;
    }
//    std::sort(r_iter.base(), nums.end());
//    auto it_first = std::upper_bound(r_iter.base(), nums.end(), *r_iter);
    auto it_first = std::upper_bound(nums.rbegin(), r_iter, *r_iter);
    std::swap(*it_first, *(r_iter));
//    std::sort(r_iter.base(), nums.end());
    std::reverse(r_iter.base(), nums.end());
}

using std::cout;
using std::endl;

int main() {
    cout << "\n\nProblem 31: Next Permutation: \n";
    std::vector<int> pervec{1, 3, 2};
    nextPermutation2(pervec);
    for (auto &i : pervec)
        cout << i << " ";
    cout << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}