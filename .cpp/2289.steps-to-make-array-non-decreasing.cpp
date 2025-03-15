/*
 * @lc app=leetcode id=2289 lang=cpp
 *
 * [2289] Steps to Make Array Non-decreasing
 */

// @lc code=start
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty() || nums[i] <= st.top()) {
                st.push(nums[i]);
            }
            else {
                res += st.top() - nums[i];
                st.pop();
                st.push(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
