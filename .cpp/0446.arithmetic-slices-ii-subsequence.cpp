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
        long ans = 0;
        vector<unordered_map<long, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)nums[i] - nums[j];
                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};
// @lc code=end
