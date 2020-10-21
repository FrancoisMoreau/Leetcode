//
// Created by brayden on 2020-10-13.
//

#include "earliest_time.h"

int earliest_time(int numofbuildings, std::vector<int> building_open_time, std::vector<int> offloadtime) {
    std::sort(building_open_time.begin(), building_open_time.end());
    std::sort(offloadtime.begin(), offloadtime.end(), std::greater<>());
    int time = -1;
    for (int i = 0; i < numofbuildings; i++) {
        time = std::max(time, building_open_time[i] +  offloadtime[4 * i]);
    }
    return time;
}