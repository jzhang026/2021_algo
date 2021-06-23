// https://leetcode-cn.com/problems/subarray-sum-equals-k/
//  和为K的子数组
// 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    // 前面补0， 让前缀和算的比较舒服
    nums = [0].concat(nums);
    let s = [0];
    for (let i = 1; i < nums.length; i++) {
        s[i] = s[i-1] + nums[i];
    }

    let countMap = {};
    for (let i = 0; i < s.length; i++) {
        countMap[s[i]] = countMap[s[i]] || 0;
        countMap[s[i]]++;
    }

    let res = 0;

    for (let i = 1; i < nums.length; i++) {
        if (countMap[s[i] - k]) {
            console.log(s[i] - k);
            res += countMap[s[i] - k];
        }
    }

    return res;
};