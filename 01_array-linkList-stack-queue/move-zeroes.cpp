// https://leetcode-cn.com/problems/move-zeroes/

// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                nums[j++]=nums[i];
            }
        }
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};