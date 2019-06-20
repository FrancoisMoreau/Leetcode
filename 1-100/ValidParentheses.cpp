
inline char parenthesesMatch(char c) {
    if (c == ')')
        return '(';
    else if (c == ']')
        return '[';
    else
        return '{';
}

bool isValid(std::string s) {
    std::string left;
    for (auto it = s.cbegin(); it != s.cend(); ++it) {
        if (*it == '(' || *it == '[' || *it == '{')
            left += *it;
        else {
            if (left.back() != parenthesesMatch(*it))
                return false;
            else left.pop_back();
        }
    }
    return true;
}
