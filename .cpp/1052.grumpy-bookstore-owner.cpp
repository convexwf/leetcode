/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
// 1. 累计和数组
// 2023-09-22 submission
// 78/78 cases passed
// Runtime: 29 ms, faster than 44.43% of cpp online submissions.
// Memory Usage: 32.8 MB, less than 6.26% of cpp online submissions.
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), total = 0;
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            total += customers[i];
            sum[i + 1] = sum[i] + customers[i] * grumpy[i];
        }
        int maxSatisfied = 0;
        for (int i = 0; i + minutes <= n; ++i) {
            maxSatisfied = max(maxSatisfied, sum[i + minutes] - sum[i]);
        }
        return total - sum[n] + maxSatisfied;
    }
};
// @lc code=end
