// https://leetcode-cn.com/problems/range-sum-query-2d-immutable/

// 二维区域和检索 - 矩阵不可变
// 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        sum_arr.clear();
        for (int i = 0; i < matrix.size(); i++) {
            sum_arr.push_back({});
            // 0， 0， i, j 顶点的和
            for (int j = 0; j < matrix[i].size(); ++j) {
                sum_arr[i].push_back(get_sum(i - 1, j) + get_sum(i, j - 1) - get_sum(i - 1, j - 1) + matrix[i][j]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return get_sum(row2, col2) - get_sum(row1 - 1, col2) - get_sum(row2, col1 - 1) + get_sum(row1 - 1, col1 - 1);
    }

private:
    vector<vector<int>> sum_arr;

    int get_sum(int i, int j) {
        if (i < 0 || j < 0) return 0;
        return sum_arr[i][j];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */