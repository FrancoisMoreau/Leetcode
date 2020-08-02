//
// Created by brayden on 2020-02-27.
//

#include "problem273.h"
#include <vector>

using std::vector;


string onebit(int num) {
    switch(num) {
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return "Zero";
    }
}

string tenbits(int num) {
    switch(num) {
        case 2: return "Twenty";
        case 3: return "Thirty";
        case 4: return "Forty";
        case 5: return "Fifty";
        case 6: return "Sixty";
        case 7: return "Seventy";
        case 8: return "Eighty";
        default: return "Ninety";
    }
}

string special_case(int num) {
    switch(num) {
        case 10: return "Ten";
        case 11: return "Eleven";
        case 12: return "Twelve";
        case 13: return "Thirteen";
        case 14: return "Fourteen";
        case 15: return "Fifteen";
        case 16: return "Sixteen";
        case 17: return "Seventeen";
        case 18: return "Eighteen";
        default: return "Nineteen";
    }
}

string threebit_helper(int num) {
    string res;
    if (num / 100) {
        res += onebit(num / 100) + " Hundred ";
    }
    num %= 100;
    if (num / 10 == 1) {
        return res += special_case(num);
    }
    if (num / 10) res += tenbits(num / 10) + " ";
    num %= 10;
    if (num) res += onebit(num);
    return res;
}

string numberToWords2(int num) {
    if (!num) return "Zero";
    string result;
    if (num / 1000000000) {
        result += threebit_helper(num / 1000000000);
        if (result.back() == ' ') result.pop_back();
        result += " Billion ";
    }
    num %= 1000000000;
    if (num / 1000000) {
        result += threebit_helper(num / 1000000);
        if (result.back() == ' ') result.pop_back();
        result += " Million ";
    }
    num %= 1000000;
    if (num / 1000) {
        result += threebit_helper(num / 1000);
        if (result.back() == ' ') result.pop_back();
        result += " Thousand ";
    }
    num %= 1000;
    result += threebit_helper(num);

    if (result.back() == ' ') result.pop_back();
    return result;
}

//another short solution

string int_string(int num, const vector<string> &below_100, const vector<string> &below_20) {
    if (num >= 1000000000) return int_string(num / 1000000000, below_100, below_20) + " Billion" + int_string(num - 1000000000 * (num / 1000000000), below_100, below_20);
    else if (num >= 1000000) return int_string(num / 1000000, below_100, below_20) + " Million" + int_string(num - 1000000 * (num / 1000000), below_100, below_20);
    else if (num >= 1000) return int_string(num / 1000, below_100, below_20) + " Thousand" + int_string(num - 1000 * (num / 1000), below_100, below_20);
    else if (num >= 100) return int_string(num / 100, below_100, below_20) + " Hundred" + int_string(num - 100 * (num / 100), below_100, below_20);
    else if (num >= 20) return string(" ") + below_100[num / 10 - 2] + int_string(num - 10 * (num / 10), below_100, below_20);
    else if (num >= 1) return string(" ") + below_20[num - 1];
    else return "";
}

string numberToWords(int num) {
    vector<string> below_100{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> below_20{"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    if (num == 0) return "Zero";
    else return int_string(num, below_100, below_20).substr(1);
}