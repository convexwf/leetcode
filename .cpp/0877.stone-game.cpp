/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
// 1. 动态规划
// 2023-08-04 submission
// 46/46 cases passed
// Runtime: 18 ms, faster than 49.22% of cpp online submissions.
// Memory Usage: 16.5 MB, less than 23.5% of cpp online submissions.
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};
// @lc code=end

// @lc code=start
// 2. minmax
// 2023-08-04 submission
// 46/46 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 63.46% of cpp online submissions.
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return helper(piles, 0, 0, 0, (int)piles.size() - 1, 0);
    }
    bool helper(vector<int>& piles, int cur0, int cur1, int left, int right, int player) {
        if (left > right) return cur0 > cur1;
        if (player == 0) {
            return helper(piles, cur0 + piles[left], cur1, left + 1, right, 1) ||
                   helper(piles, cur0 + piles[right], cur1, left + 1, right, 1);
        }
        else {
            return helper(piles, cur0, cur1 + piles[left], left, right - 1, 0) ||
                   helper(piles, cur0, cur1 + piles[right], left, right - 1, 0);
        }
    }
};
// @lc code=end

// @lc code=start
// 3. 数学方法
// 2023-08-04 submission
// 46/46 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.4 MB, less than 78.58% of cpp online submissions.
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
// @lc code=end
