/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
// 1. DFS+剪枝
// 2023-05-26 submission
// 195/195 cases passed
// Runtime: 775 ms, faster than 16.19% of cpp online submissions.
// Memory Usage:  MB, less than 95.03% of cpp online submissions.
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
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
            if (dfs(matchsticks, sides, index + 1, side)) return true;
            sides[i] -= matchsticks[index];
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        int target = sum / 4;
        vector<int> dp(1 << n, false); // n 最大为 15，所以 1 << n 最大为 2^15=32768
        dp[0] = true;
        for (int i = 0; i < (1 << n); ++i) {
            if (!dp[i]) continue;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) continue;
                int next = i | (1 << j);
                if (dp[next]) continue;
                if (matchsticks[j] > target) continue;
                if (matchsticks[j] == target) {
                    dp[next] = true;
                    break;
                }
                dp[next] = dp[i];
            }
        }
        return dp[(1 << n) - 1];
    }
};
// @lc code=end