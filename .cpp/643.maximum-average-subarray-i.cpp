/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
// 1. 滑动窗口
// 2023-08-11 submission
// 127/127 cases passed
// Runtime: 149 ms, faster than 80.56% of cpp online submissions.
// Memory Usage: 109.5 MB, less than 73.04% of cpp online submissions.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i >= k - 1) {
                maxSum = max(maxSum, sum);
                sum -= nums[i - k + 1];
            }
        }
        return (double)maxSum / k;
    }
};
// @lc code=end

// @lc code=start
// 2. 前缀和
// 2023-08-11 submission
// 127/127 cases passed
// Runtime: 124 ms, faster than 97.74% of cpp online submissions.
// Memory Usage: 114.8 MB, less than 6.23% of cpp online submissions.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        double res = sums[k] * 1.0 / k;
        for (int i = k + 1; i <= n; ++i) {
            res = max(res, (sums[i] - sums[i - k]) * 1.0 / k);
        }
        return res;
    }
};
// @lc code=end
