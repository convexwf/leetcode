/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (59.95%)
 * Likes:    7951
 * Dislikes: 108
 * Total Accepted:    745.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 *
 *
 */

// @lc code=start
// 2022-07-28 submission
// 61/61 cases passed
// Runtime: 15 ms, faster than 53.74% of C++ online submissions.
// Memory Usage: 9.6 MB, less than 90.08% of C++ online submissions.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) dp[j] += grid[i][j];
                else dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        return dp.back();
    }
};
// @lc code=end