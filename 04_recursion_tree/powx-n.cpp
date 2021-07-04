// https://leetcode-cn.com/problems/powx-n/

// 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 1) return x;
        if (n == 0) return 1;
        if (n < 0) {
            return 1 / myPow(x, -n);
        }
        double temp = myPow(x, n / 2);
        return n % 2 == 1 ? temp * temp * x : temp * temp;
    }
};