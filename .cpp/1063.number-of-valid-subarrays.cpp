/*
 * @lc app=leetcode id=1063 lang=cpp
 *
 * [1063] Number of Valid Subarrays
 */

// @lc code=start
// 1. 单调递增栈
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                res += i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            res += n - st.top();
            st.pop();
        }
        return res;
    }
};
// @lc code=end
