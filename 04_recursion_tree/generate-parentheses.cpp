// https://leetcode-cn.com/problems/generate-parentheses/

// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

#include "string"
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        if (h.find(n) != h.end()) return h[n];

        vector<string> ans;
        for (int k = 1; k <= n; k++) {
            // 子问题分解
            // (a) b
            // 通过限定第一个括号来分解子问题
            // 子问题的分解要不重不漏
            auto a = generateParenthesis(k - 1);
            auto b = generateParenthesis(n - k);
            for (string &a_str : a)
                for (string &b_str : b)
                    ans.push_back("(" + a_str + ")" + b_str);
        }
        return ans;
    }


private:
    // map来作为缓存，避免相同数字的重复计算
    unordered_map<int, vector<string>> h;
};

