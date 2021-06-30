// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
// 柱状图中最大的矩形
// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。
#include "vector"
#include "stack"
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<Rect> s;
        int ans = 0;
        for (int h : heights) {
            int width = 0;
            // 若heights[i - 1] > heights[i], 则 heights[i - 1]
            // 就无法影响后面的计算，就可以单独计算
            while (!s.empty() && s.top().height >= h) {
                width += s.top().width;
                ans = max(ans, s.top().height * width);
                s.pop();
            }
            // 把目前无法计算的状态和数值入栈
            s.push({h, width + 1});
        }

        // 为了清理剩下的栈
        int width = 0;
        while (!s.empty()) {
            width += s.top().width;
            ans = max(ans, s.top().height * width);
            s.pop();
        }
        return ans;
    }

private:
    struct Rect {
        int height;
        int width;
    };
};