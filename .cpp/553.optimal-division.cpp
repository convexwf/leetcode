/*
 * @lc app=leetcode id=553 lang=cpp
 *
 * [553] Optimal Division
 */

// @lc code=start
// 1. 数学方法
// 2023-10-31 submission
// 93/93 cases passed
// Runtime: 4 ms, faster than 28.66% of cpp online submissions.
// Memory Usage: 8.6 MB, less than 9.76% of cpp online submissions.
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);
        if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            res += "/" + to_string(nums[i]);
        }
        res += ")";
        return res;
    }
};
// @lc code=end
