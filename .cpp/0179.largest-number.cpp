/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
// 2022-11-14 submission
// 232/232 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 15.2 MB, less than 62.82% of cpp online submissions.
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res[0] == '0' ? "0" : res;
    }
};
// @lc code=end
