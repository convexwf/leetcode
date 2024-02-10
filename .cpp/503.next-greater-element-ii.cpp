/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
// 2022-08-26 submission
// 223/223 cases passed
// Runtime: 49 ms, faster than 68.06% of C++ online submissions.
// Memory Usage: 23.9 MB, less than 78.07% of C++ online submissions.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};
// @lc code=end