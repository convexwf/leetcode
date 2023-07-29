/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
// 1. 栈
// 2023-07-26 submission
// 152/152 cases passed
// Runtime: 7 ms, faster than 87.81% of cpp online submissions.
// Memory Usage: 15.4 MB, less than 49.89% of cpp online submissions.
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (int num : pushed) {
            s.push(num);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};
// @lc code=end
