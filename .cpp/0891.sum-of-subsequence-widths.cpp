/*
 * @lc app=leetcode id=891 lang=cpp
 *
 * [891] Sum of Subsequence Widths
 */

// @lc code=start
// 1. 排序
// 2023-12-28 submission
// 68/68 cases passed
// Runtime: 221 ms, faster than 5.3% of cpp online submissions.
// Memory Usage: 54.3 MB, less than 41.67% of cpp online submissions.
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        const int mod = 1e9 + 7;
        long long res = 0, p = 1;
        for (int i = 0; i < n; ++i) {
            res = (res + (nums[i] - nums[n - i - 1]) * p) % mod;
            p = (p << 1) % mod;
        }
        return res;
    }
};
// @lc code=end
