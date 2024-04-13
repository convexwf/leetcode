/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
// 2021-03-10 submission
// 130/130 cases passed
// Runtime: 150 ms, faster than 35.49% of cpp online submissions.
// Memory Usage: 14.7 MB, less than 92.09% of cpp online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int x = 0, y = cols - 1;
        while (x < rows && y >= 0) {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] < target)
                ++x;
            else if (matrix[x][y] > target)
                --y;
        }
        return false;
    }
};
// @lc code=end
