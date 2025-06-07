/*
 * @lc app=leetcode id=691 lang=cpp
 *
 * [691] Stickers to Spell Word
 */

// @lc code=start
// 1. 动态规划
// 2025-06-05 submission
// 102/102 cases passed
// Runtime: 451 ms, faster than 32.8% of cpp online submissions.
// Memory Usage: 375.5 MB, less than 18.82% of cpp online submissions.
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size(), m = target.size();
        const int size = 1 << m;
        vector<int> dp(size, INT_MAX);
        dp[0] = 0;

        for (int mask = 0; mask < size; ++mask) {
            if (dp[mask] == INT_MAX) continue;
            for (const string& sticker : stickers) {
                int newMask = mask;
                vector<int> count(26, 0);
                for (char c : sticker) {
                    count[c - 'a']++;
                }
                for (int i = 0; i < target.size(); ++i) {
                    if ((mask & (1 << i)) == 0 && count[target[i] - 'a'] > 0) {
                        newMask |= (1 << i);
                        count[target[i] - 'a']--;
                    }
                }
                dp[newMask] = min(dp[newMask], dp[mask] + 1);
            }
        }

        return dp[size - 1] == INT_MAX ? -1 : dp[size - 1];
    }
};
// @lc code=end
