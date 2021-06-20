//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                nums[j++] = nums[i];
                last = nums[i];
                continue;
            }
            if (nums[i] == last) {
                continue;
            }
            nums[j++] = nums[i];
            last = nums[i];
        }
        return j;
    }
};