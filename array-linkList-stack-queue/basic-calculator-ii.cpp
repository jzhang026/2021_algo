// https://leetcode-cn.com/problems/basic-calculator-ii/
// 基本计算器 II

// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

// 整数除法仅保留整数部分。

// 提示：

// 1 <= s.length <= 3 * 105
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
// s 表示一个 有效表达式
// 表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
// 题目数据保证答案是一个 32-bit 整数

#include <stack>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int calculate(string s) {
        vector<string> tokens;
        stack<char> ops;
        long long val = 0;
        bool parsingNumber = false;;
        bool needs_zero = false;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                val = val * 10 + ch - '0';
                parsingNumber = true;
                continue;
            }

            if (parsingNumber) {
                tokens.push_back(to_string(val));
                val = 0;
                parsingNumber = false;
                needs_zero = false;
            }

            if (ch == ' ') continue;

            if (ch == '(') {
                ops.push(ch);
                needs_zero = true;
                continue;
            }

            if (ch == ')') {
                while(ops.top()!= '(') {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.pop();
                needs_zero = false;
                continue;
            }
            if (needs_zero) tokens.push_back(to_string(0));
            while(!ops.empty() && getRank(ops.top()) >= getRank(ch)) {
                tokens.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(ch);
            needs_zero = true;
        }
        if (parsingNumber) tokens.push_back(to_string(val));
        while (!ops.empty()) {
            tokens.push_back(string(1, ops.top()));
            ops.pop();
        }

        return evalRPN(tokens);
    }

private:
    int getRank(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token : tokens) {
            if (isOperator(token)) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(calc(a, b, token));
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }

    int calc(int a, int b, string token) {
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        if (token == "/") return a / b;
        return 0;
    }

    bool isOperator(string token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};