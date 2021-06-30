// https://leetcode-cn.com/problems/two-sum/

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个 整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

#include "vector"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numbers;
        for (int i = 0; i < nums.size(); i++) {
            numbers.push_back(make_pair(nums[i], i));
        }

        sort(numbers.begin(), numbers.end());
        int j = numbers.size() - 1;

        for (int i = 0; i < numbers.size(); ++i) {
            while (i < j && numbers[i].first + numbers[j].first > target) j--;
            if (numbers[i].first + numbers[j].first == target) return {numbers[i].second, numbers[j].second};
        }
        return {};
    }
};