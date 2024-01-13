/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
// 1. 前缀和+分类讨论
// 2024-01-10 submission
// 51/51 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 53.53% of cpp online submissions.
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        int res = 0, firstMax = 0, secondMax = 0;
        for (int i = firstLen; i + secondLen <= n; ++i) {
            firstMax = max(firstMax, prefixSum[i] - prefixSum[i - firstLen]);
            res = max(res, firstMax + prefixSum[i + secondLen] - prefixSum[i]);
        }
        for (int i = secondLen; i + firstLen <= n; ++i) {
            secondMax = max(secondMax, prefixSum[i] - prefixSum[i - secondLen]);
            res = max(res, secondMax + prefixSum[i + firstLen] - prefixSum[i]);
        }
        return res;
    }
};
// @lc code=end
