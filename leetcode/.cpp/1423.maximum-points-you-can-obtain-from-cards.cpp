/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
// 1. 滑动窗口
// 2025-03-28 submission
// 40/40 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 46.1 MB, less than 79.6% of cpp online submissions.
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = n - k; i < n; ++i) {
            sum += cardPoints[i];
        }
        int maxSum = sum;
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[i] - cardPoints[n - k + i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
// @lc code=end
