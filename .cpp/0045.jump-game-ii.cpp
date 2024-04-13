/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
// 2022-07-28 submission
// 109/109 cases passed
// Runtime: 23 ms, faster than 72.87% of cpp online submissions.
// Memory Usage: 16.5 MB, less than 96.6% of cpp online submissions.
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int res = 1;
        int pre = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > pre) {
                pre = cur;
                ++res;
            }
            cur = max(cur, i + nums[i]);
            if (cur >= nums.size() - 1) break;
        }
        return res;
    }
};
// @lc code=end
