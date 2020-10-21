//
// Created by brayden on 2020-10-13.
//

#include "laboratory.h"

#include <set>

int laboratory(std::vector<int> requirements, int flasktypes, const std::vector<std::vector<int>> &markings) {
    std::vector<std::set<int>> marks(flasktypes, std::set<int>());
    for (auto &marking : markings) {
        marks[marking[0]].insert(marking[1]);
    }

    std::sort(requirements.begin(), requirements.end(), std::greater<>());
    int idx = -1, min = INT_MAX;
    for (int i = 0; i < marks.size(); i++) {
        int cur_waste = 0;
        for (int requires : requirements) {
            auto iter = marks[i].lower_bound(requires);
            if (iter == marks[i].end()) {
                cur_waste = INT_MAX;
                break;
            }
            if (*iter == requires) continue;
            if (iter != marks[i].begin()) iter--;
            if (*iter < requires) iter++;
            cur_waste += (*iter - requires);
        }
        if (cur_waste < min) {
            min = cur_waste;
            idx = i;
        }
    }
    return idx;
}