/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
// 1. 贪心算法
// 2023-10-04 submission
// 146/146 cases passed
// Runtime: 4 ms, faster than 69.43% of cpp online submissions.
// Memory Usage: 11.7 MB, less than 16.23% of cpp online submissions.
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        long long x = 1;
        int i = 0;
        while (x <= n) {
            if (i < nums.size() && nums[i] <= x) {
                x += nums[i++];
            }
            else {
                x *= 2;
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
