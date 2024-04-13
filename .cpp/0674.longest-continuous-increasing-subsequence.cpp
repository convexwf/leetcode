/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
// 2022-11-15 submission
// 35/35 cases passed
// Runtime: 25 ms, faster than 41.59% of cpp online submissions.
// Memory Usage: 11 MB, less than 18.53% of cpp online submissions.
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 1, cnt = 1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i])
                res = max(res, ++cnt);
            else
                cnt = 1;
        }
        return res;
    }
};
// @lc code=end
