/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
// 1. 动态规划
// 2022-08-11 submission
// 188/188 cases passed
// Runtime: 16 ms, faster than 29.27% of cpp online submissions.
// Memory Usage: 14.3 MB, less than 6.35% of cpp online submissions.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> plus(nums.size(), 0);
        vector<int> minus(nums.size(), 0);
        int maxValue = nums[0];
        plus[0] = minus[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            plus[i] = max(max(plus[i - 1] * nums[i], minus[i - 1] * nums[i]), nums[i]);
            minus[i] = min(min(plus[i - 1] * nums[i], minus[i - 1] * nums[i]), nums[i]);
            maxValue = max(maxValue, plus[i]);
        }
        return maxValue;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划-空间优化
// 2022-08-11 submission
// 188/188 cases passed
// Runtime: 4 ms, faster than 94.17% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 71.85% of cpp online submissions.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], mx = res, mn = res;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(mx, mn);
            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);
            res = max(res, mx);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 累计乘积数组
// 2022-08-11 submission
// 188/188 cases passed
// Runtime: 12 ms, faster than 53.36% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 71.85% of cpp online submissions.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], prod = 1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            res = max(res, prod *= nums[i]);
            if (nums[i] == 0) prod = 1;
        }
        prod = 1;
        for (int i = n - 1; i >= 0; --i) {
            res = max(res, prod *= nums[i]);
            if (nums[i] == 0) prod = 1;
        }
        return res;
    }
};
// @lc code=end
