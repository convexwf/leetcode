/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
// 2022-07-21 submission
// 21/21 cases passed
// Runtime: 3 ms, faster than 63.72% of C++ online submissions.
// Memory Usage: 6.9 MB, less than 99.81% of C++ online submissions.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp = 0;
        for (int x = 0; x < (n + 1) / 2; x++) {
            for (int y = 0; y < n / 2; y++) {
                temp = matrix[n - 1 - y][x];
                matrix[n - 1 - y][x] = matrix[n - 1 - x][n - 1 - y];
                matrix[n - 1 - x][n - 1 - y] = matrix[y][n - 1 - x];
                matrix[y][n - 1 - x] = matrix[x][y];
                matrix[x][y] = temp;
            }
        }
    }
};
// @lc code=end

// @lc code=start
// 2022-07-21 submission
// 21/21 cases passed
// Runtime: 3 ms, faster than 63.72% of C++ online submissions.
// Memory Usage: 7.2 MB, less than 33.2% of C++ online submissions.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end