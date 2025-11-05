/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
// 1. dfs+剪枝
// 2023-05-26 submission
// 195/195 cases passed
// Runtime: 775 ms, faster than 16.19% of cpp online submissions.
// Memory Usage:  MB, less than 95.03% of cpp online submissions.
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        int side = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sides(4, 0);
        return dfs(matchsticks, sides, 0, side);
    }

    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int side) {
        if (index == matchsticks.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchsticks[index] > side) continue;
            sides[i] += matchsticks[index];
            if (dfs(matchsticks, sides, index + 1, side)) {
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划+状态压缩
// 2025-06-07 submission
// 195/195 cases passed
// Runtime: 87 ms, faster than 66.97% of cpp online submissions.
// Memory Usage: 22.9 MB, less than 15.57% of cpp online submissions.
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        int side = sum / 4;
        int n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    int nextMask = mask | (1 << i);
                    int nextSum = dp[mask] + matchsticks[i];
                    if (nextSum <= side) {
                        dp[nextMask] = nextSum % side;
                    }
                }
            }
        }

        return dp[(1 << n) - 1] == 0;
    }
};
// @lc code=end
