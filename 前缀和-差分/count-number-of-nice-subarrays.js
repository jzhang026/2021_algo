// https://leetcode-cn.com/problems/count-number-of-nice-subarrays

// 统计「优美子数组」
// 给你一个整数数组 nums 和一个整数 k。
//
// 如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
//
// 请返回这个数组中「优美子数组」的数目。

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numberOfSubarrays = function(nums, k) {
    nums = [0].concat(nums);
    let s = [0];
    for (let i = 1; i< nums.length; i++) {
        s[i] = s[i - 1] + nums[i] % 2;
    }

    let count = [];
    for (let i = 0; i < s.length; i++) {
        count[s[i]] = count[s[i]] || 0;
        count[s[i]]++;
    }
    let res = 0;
    for (let i = 1; i < s.length; i++) {
        if (s[i] - k >= 0) res += count[s[i] - k];
    }
    return res

};