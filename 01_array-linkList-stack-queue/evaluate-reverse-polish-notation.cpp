// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
// 逆波兰表达式求值

//根据 逆波兰表示法，求表达式的值。
//
//有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//说明：
//
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
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
private:
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