/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
// 2022-07-30 submission
// 70/70 cases passed
// Runtime: 174 ms, faster than 30.24% of cpp online submissions.
// Memory Usage: 51.5 MB, less than 51.51% of cpp online submissions.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.count(nums[i]))
                return true;
            else
                st.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end
