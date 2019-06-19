int maxArea(std::vector<int>& height) {
    int area  = 0;
    auto left = height.cbegin(), right = height.cend() - 1;
    while (left != right) {
        int cur_area = std::min(*left, *right) * (right - left);
        area = area > cur_area ? area : cur_area;
        if (*left > *right) right--;
        else left++;
    }
    return  area;
}
