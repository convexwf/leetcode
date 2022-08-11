/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (34.79%)
 * Likes:    12995
 * Dislikes: 393
 * Total Accepted:    824.6K
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find a contiguous non-empty subarray within the
 * array that has the largest product, and return the product.
 *
 * The test cases are generated so that the answer will fit in a 32-bit
 * integer.
 *
 * A subarray is a contiguous subsequence of the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 */

// @lc code=start
// 2022-08-11 submission
// 188/188 cases passed
// Runtime: 16 ms, faster than 29.27% of C++ online submissions.
// Memory Usage: 14.3 MB, less than 6.35% of C++ online submissions.
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
// 2022-08-11 submission
// 188/188 cases passed
// Runtime: 4 ms, faster than 94.17% of C++ online submissions.
// Memory Usage: 13.8 MB, less than 71.85% of C++ online submissions.
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
// 2022-08-11 submission
// 188/188 cases passed
// Runtime: 12 ms, faster than 53.36% of C++ online submissions.
// Memory Usage: 13.8 MB, less than 71.85% of C++ online submissions.
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
