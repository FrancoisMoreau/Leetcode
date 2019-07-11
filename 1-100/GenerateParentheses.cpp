//对于这种格式，　第一步应该本能的想到，　和单链表，　二叉树等递归结构一样，想到利用递归。　

//比较容易理解的一种递归写法
void combine(vector<string> &res, string &path, int left, int right, int n) {
    if (left == n) {
        res.push_back(path + string(n - right, ')'));
        return ;
    }
    path += "(";
    combine(res, path, left + 1, right, n);
    path.pop_back();
    if (left > right) {
        path += ")";
        combine(res, path, left, right + 1, n);
        path.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string path;
    if (n > 0) combine(result, path, 0, 0, n);
    return result;
}

//这种写法更难理解一些，　但代码很简洁，　目前也不是特别理解。。

vector<string> generate(int n) {
    if (n == 0) return vector<string>(1, "");
    if (n == 1) return vector<string>(1, "()");
    vector<string> result;

    for (int i = 0; i < n; ++i) {
        for (auto inner : generate(i)) {
            for (auto outter : generate(n - 1 - i)) {
                result.push_back("(" + inner + ")" + outter);
            }
        }
    }
    return result;
}
