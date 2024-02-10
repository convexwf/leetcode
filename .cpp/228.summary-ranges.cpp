/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
// 2020-10-29 submission
// 29/29 cases passed
// Runtime: 4 ms, faster than 26.96% of C++ online submissions.
// Memory Usage: 6.9 MB, less than 33.49% of C++ online submissions.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            int j = 1;
            while (i + j < n && nums[i + j] - j == nums[i]) ++j;
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return res;
    }
};
// @lc code=end
