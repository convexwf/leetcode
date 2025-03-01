/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
// 1. 单调递减栈
// 2025-02-25 submission
// 107/107 cases passed
// Runtime: 12 ms, faster than 51.72% of cpp online submissions.
// Memory Usage: 70.7 MB, less than 35.81% of cpp online submissions.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int third = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < third) {
                return true;
            }
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end
