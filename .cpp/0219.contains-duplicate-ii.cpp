/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
// 1. 哈希表
// 2019-09-17 submission
// 54/54 cases passed
// Runtime: 166 ms, faster than 98.33% of cpp online submissions.
// Memory Usage: 77.3 MB, less than 43.01% of cpp online submissions.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i]) && i - m[nums[i]] <= k) {
                return true;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end
