/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
// 2022-11-15 submission
// 5833/5833 cases passed
// Runtime: 163 ms, faster than 79.08% of C++ online submissions.
// Memory Usage: 96.1 MB, less than 84.61% of C++ online submissions.
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                if (j == 0 || grid[i][j - 1] == 0) ++res;
                if (i == 0 || grid[i - 1][j] == 0) ++res;
                if (j == n - 1 || grid[i][j + 1] == 0) ++res;
                if (i == m - 1 || grid[i + 1][j] == 0) ++res;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-15 submission
// 5833/5833 cases passed
// Runtime: 240 ms, faster than 39.91% of C++ online submissions.
// Memory Usage: 96.1 MB, less than 84.61% of C++ online submissions.
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                res += 4;
                if (i > 0 && grid[i - 1][j] == 1) res -= 2;
                if (j > 0 && grid[i][j - 1] == 1) res -= 2;
            }
        }
        return res;
    }
};
// @lc code=end