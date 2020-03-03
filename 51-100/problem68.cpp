//
// Created by brayden on 2020-02-27.
//

#include "problem68.h"

// general thought is good, but the way I construct my code is terrible
vector<string> fullJustify2222(vector<string>& words, int maxWidth) {
    vector<string> output;
    string cur_line;
    int cur_len = 0, start = 0, indent = 0;
    for (int i = 0; i < words.size(); ++i) {
        cur_len += words[i].size() + 1;
        if (cur_len > maxWidth + 1) {
            if (i - 1 - start < 1) {
                output.push_back(words[i - 1] + string(maxWidth - words[i - 1].size(), ' '));
            } else {
                int total_space = maxWidth + 2 - cur_len + words[i].size();
                indent = 1 + total_space / (i - start - 1);
                int prev_ind = total_space % (i - start - 1);
                cur_line = words[start];
                for (int j = start + prev_ind; start < j; ++start) {
                    cur_line += string(indent + 1, ' ');
                    cur_line += words[start + 1];
                }
                for (; start < i; ++start) {
                    cur_line += words[start] + string(indent, ' ');
                }
            }
            --i;
            output.push_back(cur_line);
            cur_line = "";
            cur_len = 0;
        }
        if (i == words.size() - 1) {
            start++;
            for (; start < words.size(); ++start) {
                cur_line += words[start] + " ";
            }
            cur_line += string(maxWidth + 1 - cur_line.size(), ' ');

            output.push_back(cur_line);
        }
    }
    return output;

}

// to trim std::string
//https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

//Coped from discussion
vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;
    for (int i = 0, j; i < words.size(); i = j) {
        int width = 0;
        for (j = i; j < words.size() && width + words[j].size() + j - i <= maxWidth; ++j) {
            width += words[j].size();
        }
        int space = 1, extra = 0;
        if (j - i != 1 && j != words.size()) {
            space = (maxWidth - width) / (j - i - 1);
            extra = (maxWidth - width) % (j - i - 1);
        }
        string line(words[i]);
        for (int k = i + 1; k < j; ++k) {
            line += string(space, ' ');
            if (extra-- > 0)
                line += " ";
            line += words[k];
        }
        line +=  string(maxWidth - line.size(), ' ');
        res.push_back(line);
    }
    return res;

}
// first go forward k steps, to see the upper_bound
// then, if it's not the end or only one word, calculate the space + extra space
// add space between the words, to do this, first initialize the value, if we there are other words left, add ' ' and word
// last several lines for complete the line