//
// Created by brayden on 2020-02-28.
//

#include "problem609.h"
#include <unordered_map>
#include <sstream>

using std::unordered_map;

// my solution
vector<vector<string>> findDuplicate(vector<string>& paths) {
    string path_head, path_tails;
    unordered_map<string, vector<string>> dict;
    for (auto &i : paths) {
        auto indent = i.find(' ');

        path_head = i.substr(0, indent);
        path_tails = i.substr(indent + 1);
        while (indent != std::string::npos) {
            auto left = path_tails.find('(');
            auto right = path_tails.find(')');
            dict[path_tails.substr(left + 1, right - left - 1)].push_back(path_head + '/' +  path_tails.substr(0, left));
            indent = path_tails.find(' ');
            if (indent != std::string::npos) path_tails = path_tails.substr(indent + 1);
        }
    }
    vector<vector<string>> res;
    for (auto &i : dict) {
        if (i.second.size() > 1)
            res.push_back(i.second);
    }
    return res;
}

// we could implement the stringsteam to solve this problem
vector<vector<string>> findDuplicate2(vector<string>& paths) {
    unordered_map<string, vector<string>> files;
    vector<vector<string>> result;
    for (auto path : paths) {
        std::stringstream ss(path);
        string root;
        string s;
        getline(ss, root, ' ');
        while (getline(ss, s, ' ')) {
            string fileName = root + '/' + s.substr(0, s.find('('));
            string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
            files[fileContent].push_back(fileName);
        }
    }
    for (auto file : files) {
        if (file.second.size() > 1)
            result.push_back(file.second);
    }

    return result;
}