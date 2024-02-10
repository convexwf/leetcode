/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
// 2022-08-26 submission
// 22/22 cases passed
// Runtime: 39 ms, faster than 53.37% of C++ online submissions.
// Memory Usage: 24.1 MB, less than 51.99% of C++ online submissions.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            right *= nums[i + 1];
            res[i] *= right;
        }
        return res;
    }
};
// @lc code=end
