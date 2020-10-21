//
// Created by brayden on 2020-10-14.
//

#include "LRUcache.h"
#include <list>
#include <unordered_map>

int lruCacheMisses(std::vector<int> pages, int maxCacheSize) {
    std::unordered_map<int, std::list<int>::iterator> dict;
    std::list<int> pag_list;
    int count = 0;
    for (int page: pages) {
        if (dict.find(page) == dict.end()) {
            count++;
        } else {
            auto tar = dict.find(page);
            pag_list.erase(dict[page]);
            dict.erase(tar);

        }
        pag_list.push_front(page);
        dict[page] = pag_list.begin();
        if (pag_list.size() > maxCacheSize) {
            dict.erase(pag_list.back());
            pag_list.pop_back();
        }
    }
    return count;
}