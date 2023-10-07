/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
// 2022-05-30 submission
// 57/57 cases passed
// Runtime: 12 ms, faster than 83.93% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 29.71% of C++ online submissions.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i]))
                return vector<int>{m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end
