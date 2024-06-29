/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
// 1. 二分查找
// 2024-06-25 submission
// 130/130 cases passed
// Runtime: 54 ms, faster than 37.67% of cpp online submissions.
// Memory Usage: 17.4 MB, less than 50.3% of cpp online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] > target) {
                break;
            }
            if (matrix[i][n - 1] < target) {
                continue;
            }
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                }
                else if (matrix[i][mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 对角搜索
// 2021-03-10 submission
// 130/130 cases passed
// Runtime: 150 ms, faster than 35.49% of cpp online submissions.
// Memory Usage: 14.7 MB, less than 92.09% of cpp online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};
// @lc code=end
