// https://leetcode-cn.com/problems/maximum-subarray/

// 最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

#include "vector"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        // 输入数组范围从 0 ~ n - 1
        int n = nums.size();

        // 前缀和范围  0,1 ~ n
        vector<long long> sum(n + 1, 0);

        for (int i = 1; i <= n ; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        vector<long long> pre(n+1, 0);
        // 前缀最小值
        pre[0] = sum[0];
        for (int i = 1; i <= n; ++i) {
            pre[i] = min(pre[i-1], sum[i]);
        }

        long long ans = LONG_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, sum[i] - pre[i-1]);
        }
        return ans;
    }
};