//
// Created by brayden on 2020-10-15.
//

#include "gateway.h"


int gateway(const std::vector<int> &requestTime) {
    int one_sec = 0, ten_sec = 0, one_min = 0;
    int dropped = 0;
    for (int i = 0; i < requestTime.size(); i++) {
        if (requestTime[i] > requestTime[one_sec]) {
            one_sec = i;
        }
        while (requestTime[i] >= requestTime[ten_sec] + 10) {
            ten_sec++;
        }
        while (requestTime[i] > requestTime[one_min] + 60) {
            one_min++;
        }
        if (i - one_sec >= 3 || i - ten_sec >= 20 || i - one_min > 60)
            dropped++;
    }
    return dropped;
}