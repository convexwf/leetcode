/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
// 1. 记忆化搜索
// 2023-01-14 submission
// 58/58 cases passed
// Runtime: 1081 ms, faster than 29.17% of cpp online submissions.
// Memory Usage: 89.6 MB, less than 29.71% of cpp online submissions.
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) {
            return false;
        }
        unordered_map<int, bool> memo;
        return dfs(maxChoosableInteger, desiredTotal, 0, memo);
    }

    bool dfs(int maxChoosableInteger, int desiredTotal, int masks, unordered_map<int, bool>& memo) {
        if (memo.count(masks)) {
            return memo[masks];
        }
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            int mask = 1 << i;
            if ((masks & mask) == 0) {
                if (i >= desiredTotal ||
                    !dfs(maxChoosableInteger, desiredTotal - i, masks | mask, memo)) {
                    memo[masks] = true;
                    return true;
                }
            }
        }
        memo[masks] = false;
        return false;
    }
};
// @lc code=end
