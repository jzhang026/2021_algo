// https://leetcode-cn.com/problems/permutations-ii

// 全排列 II
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

//示例 1：
//
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
//[1,2,1],
//[2,1,1]]
//示例 2：
//
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
//提示：
//
//1 <= nums.length <= 8
//-10 <= nums[i] <= 10

#include "vector"
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        find(nums, 0);
        return ans;
    }

    void find(vector<int>& nums, int count) {
        if (count == nums.size()) {
            ans.push_back(s);
            return;
        }

        // 不能产生重复的排列。其实就是避免 同一层 的选项出现重复
        // 这里用一个数组来记录某个数字是不是已经被选
        // 由于题目规定数组元素的值在 一个区间 -10 <= nums[i] <= 10
        // 所以我们在记录的时候给每个值加一个 10的offset来避免数组下标出现负数
        vector<bool> mark_duplication = vector<bool>(21, false);
        for(int i = 0; i < nums.size(); i++) {
            if (!used[i] && !mark_duplication[nums[i]+10]) {
                mark_duplication[nums[i]+10] = true;
                s.push_back(nums[i]);
                used[i] = true;
                find(nums, count+1);
                s.pop_back();
                used[i] = false;
            }
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> s;
    vector<bool> used;
};