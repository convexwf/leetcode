/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
// 1. 单调递减栈+两次遍历
// 2022-08-26 submission
// 223/223 cases passed
// Runtime: 49 ms, faster than 68.06% of cpp online submissions.
// Memory Usage: 23.9 MB, less than 78.07% of cpp online submissions.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < 2 * n; i++) {
            while (!stk.empty() && nums[i % n] > nums[stk.top()]) {
                res[stk.top()] = nums[i % n];
                stk.pop();
            }
            if (i < n) {
                stk.push(i);
            }
        }
        return res;
    }
};
// @lc code=end
