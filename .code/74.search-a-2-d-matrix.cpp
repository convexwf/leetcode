/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 10 ms, faster than 26.38% of C++ online submissions.
// Memory Usage: 9.6 MB, less than 51.72% of C++ online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 15 ms, faster than 6.81% of C++ online submissions.
// Memory Usage: 9.6 MB, less than 5.1% of C++ online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = (int)matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 7 ms, faster than 53.15% of C++ online submissions.
// Memory Usage: 9.5 MB, less than 51.72% of C++ online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (r <= 0) return false;

        int ridx = r - 1;
        l = 0;
        r = n;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (matrix[ridx][mid] == target)
                return true;
            else if (matrix[ridx][mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return false;
    }
};
// @lc code=end
