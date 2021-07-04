// https://leetcode-cn.com/problems/corporate-flight-bookings/

// 航班预订统计

// 这里有n个航班，它们分别从 1 到 n 进行编号。
//
//有一份航班预订表bookings ，表中第i条预订记录
// bookings[i] = [firsti, lasti, seatsi]意味着：
// 在从 firsti到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi个座位。
//
//请你返回一个长度为 n 的数组answer，其中 answer[i] 是航班 i 上预订的座位总数。
//
#include "vector"

using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 准备差分数组，将一个区间的问题，转化成两个点的问题
        // 可以看到比起原数组元素，我们躲开了两个位置
        // 这是为了让我们屏蔽数组的边界条件导致的数组越界问题
        vector<int> delta(n + 2, 0); // 差分开 0 ~ n + 1
        for (vector<int>& booking: bookings) {
            int start = booking[0];
            int end = booking[1];
            int change = booking[2];
            delta[start] += change;
            delta[end + 1] -= change;
        }
        for (int i = 1; i < n + 1; ++i) {
            delta[i] = delta[i-1] + delta[i];
        }
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = delta[i+1];
        }
        return a;
    }
};