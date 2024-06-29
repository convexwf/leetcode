/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
// 1. 数学方法
// 2024-06-28 submission
// 58/58 cases passed
// Runtime: 94 ms, faster than 69.51% of cpp online submissions.
// Memory Usage: 98.2 MB, less than 70.87% of cpp online submissions.
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0, f0 = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            f0 += i * nums[i];
        }
        long res = f0;
        for (int i = 1; i < n; ++i) {
            f0 = f0 + sum - n * nums[n - i];
            res = max(res, f0);
        }
        return res;
    }
};
// @lc code=end
