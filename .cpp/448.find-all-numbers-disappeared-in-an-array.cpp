/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
// 2022-08-26 submission
// 33/33 cases passed
// Runtime: 62 ms, faster than 91.28% of cpp online submissions.
// Memory Usage: 33.7 MB, less than 83.21% of cpp online submissions.
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int dst = 0;
        for (int i = 0; i < n; i++) {
            dst = nums[i] >= 0 ? nums[i] : nums[i] + (n + 1);
            if (nums[dst - 1] >= 0) nums[dst - 1] -= (n + 1);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end
