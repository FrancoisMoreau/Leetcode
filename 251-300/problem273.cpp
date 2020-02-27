//
// Created by brayden on 2020-02-27.
//

#include "problem273.h"

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

string numberToWords(int num) {
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
class Solution {
public:
    static string numberToWords(int n) {
        if(n == 0) return "Zero";
        else return int_string(n).substr(1);
    }
private:
    static const char * const below_20[];
    static const char * const below_100[];
    static string int_string(int n) {
        if(n >= 1000000000)   return int_string(n / 1000000000) + " Billion" + int_string(n - 1000000000 * (n / 1000000000));
        else if(n >= 1000000) return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
        else if(n >= 1000)    return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
        else if(n >= 100)     return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
        else if(n >= 20)      return string(" ") + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
        else if(n >= 1)       return string(" ") + below_20[n - 1];
        else return "";
    }
};

const char * const Solution::below_20[] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char * const Solution::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};