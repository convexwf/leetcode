/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long, int>> dp(n);
        int res = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - nums[j];
                dp[i][diff] = 1 + (dp[j].count(diff) ? dp[j][diff] : 1);
                res += dp[i][diff] - 2;
            }
        }
        return res;
    }
};
// @lc code=end
