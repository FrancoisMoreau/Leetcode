#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <list>

using std::string;
using std::vector;
using std::cout;
using std::endl;

vector<int> findSubstring(string s, vector<string>& words) {
    if (s.empty() || words.empty()) return {};
    int length = words[0].size();
    int total_len = words.size() * length;
    std::unordered_map<string, int> words_map;
    for (auto &i : words) words_map[i]++;
    vector<int> found_idx;
    for (int j = 0; j < s.size() - total_len + 1; ++j) {
        std::map<string, int> search_map;
        int k = 0;
        for (k = 0; k < words.size(); ++k) {
            string cur_word = s.substr(j + k * length, length);
            if (words_map.find(cur_word) != words_map.end())
                search_map[cur_word]++;
            else
                break;
            if (search_map[cur_word] > words_map[cur_word])
                break;
        }
        if (k == words.size())
            found_idx.push_back(j);
    }
    return found_idx;
}

// some error findSubstring2
// Also, list search is too slow, abondaned
vector<int> findSubstring2(string s, vector<string>& words) {
    if (s.empty() || words.empty()) return {};
    int length = words[0].size();
    int total_len = words.size() * length;
    int words_size = words.size();
    vector<int> found_idx;
    std::list<string> list_words, tmp_words;
    for (auto &i : words) list_words.push_back(i);
    for (int i = 0; i < s.size() - total_len + 1; ++i) {
        printf("in i\n");
        tmp_words = list_words;
        for (int j = 0; j < words_size; ++j) {
//            printf("in j\n");
            string cur_word = s.substr(i + j * length, length);
            bool found = false;
            for (auto pos = tmp_words.begin(); pos != tmp_words.end(); ++pos) {
                if (*pos == cur_word) {
                    tmp_words.erase(pos);
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        if (tmp_words.empty())
            found_idx.push_back(i);
    }
    return found_idx;

}

int main() {
    printf("Test on this problem: \n");
    string s = "barfoothefoobarman";
    vector<string> words{"foo", "bar"};
    vector<int> res = findSubstring(s, words);
    for (auto &i : res)
        cout << i << " ";
    cout << endl << endl;

    s = "wordgoodgoodgoodbestword";
    words = {"word","good","best","good"};
    res = findSubstring(s, words);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}