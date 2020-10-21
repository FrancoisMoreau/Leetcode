//
// Created by brayden on 2020-10-15.
//

#include "highest_profit.h"

#include <unordered_map>


int max_supply_profit(int num_suppliers, std::vector<int> inventory, int order) {
    std::unordered_map<int, int> dict;
    int maxprice = INT_MIN;
    for (int price : inventory) {
        dict[price]++;
        maxprice = std::max(price, maxprice);
    }

    int res = 0;
    while (order > 0) {
        int maxi = std::min(order, dict[maxprice]);
        res += maxi * maxprice;
        order -= maxi;
        dict[maxprice] -= maxi;
        dict[maxprice - 1] = dict[maxprice - 1] + maxi;
        if (dict[maxprice] == 0) {
            dict.erase(maxprice);
            maxprice -= 1;
        }
    }
    return res;

}