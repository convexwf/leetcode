/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
// 1. 一维数组展开+二分查找
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 10 ms, faster than 26.38% of cpp online submissions.
// Memory Usage: 9.6 MB, less than 51.72% of cpp online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] == target) {
                return true;
            }
            else if (matrix[x][y] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 两次二分查找
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 7 ms, faster than 53.15% of cpp online submissions.
// Memory Usage: 9.5 MB, less than 51.72% of cpp online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m;
        // 第一次二分查找，找到目标值所在的行
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            else if (matrix[mid][0] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (right == 0) {
            return false;
        }

        // 第二次二分查找，在目标行上进行查找
        int row = right - 1;
        left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 3. 对角搜索
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 15 ms, faster than 6.81% of cpp online submissions.
// Memory Usage: 9.6 MB, less than 5.1% of cpp online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = (int)matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                --j;
            }
            else {
                ++i;
            }
        }
        return false;
    }
};
// @lc code=end
