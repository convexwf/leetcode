/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
// 1. 前缀和+动态规划
// 2025-03-05 submission
// 43/43 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 26.2 MB, less than 70.49% of cpp online submissions.
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Build prefix sum array
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        function<int(int)> getSumFromStart = [&](int i) {
            return prefix_sum[i + k] - prefix_sum[i];
        };

        // Build left and right arrays
        vector<int> left(n, 0), right(n, n - k);
        for (int i = k; i < n; ++i) {
            left[i] = getSumFromStart(left[i - 1]) >= getSumFromStart(i - k + 1) ? left[i - 1]
                                                                                 : i - k + 1;
        }
        for (int i = n - k - 1; i >= 0; --i) {
            right[i] = getSumFromStart(right[i + 1]) > getSumFromStart(i) ? right[i + 1] : i;
        }

        // Fix the middle subarray and find the left and right subarrays
        vector<int> res(3, 0);
        int max_sum = 0;
        for (int x = k; x <= n - 2 * k; ++x) {
            int left_sum = getSumFromStart(left[x - 1]);
            int right_sum = getSumFromStart(right[x + k]);
            int total_sum = left_sum + right_sum + getSumFromStart(x);
            if (total_sum > max_sum) {
                max_sum = total_sum;
                res = {left[x - 1], x, right[x + k]};
            }
        }
        return res;
    }
};
// @lc code=end
