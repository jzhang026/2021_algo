// https://leetcode-cn.com/problems/container-with-most-water

// 盛最多水的容器
// 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点(i,ai) 。
// 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为(i,ai) 和 (i, 0) 。
// 找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水。
#include "vector"
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        while (i<j) {
            int width = j - i;
            int minHeight = height[i] > height[j] ? height[j--] : height[i++];
            ans = max(ans, width * minHeight);
        }
        return ans;
    }
};