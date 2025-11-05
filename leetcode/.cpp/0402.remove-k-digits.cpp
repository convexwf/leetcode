/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
// 1. 贪心算法
// 2024-07-24 submission
// 43/43 cases passed
// Runtime: 15 ms, faster than 20.62% of cpp online submissions.
// Memory Usage: 10.3 MB, less than 32.16% of cpp online submissions.
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        for (char digit : num) {
            while (!stk.empty() && k > 0 && stk.top() > digit) {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }
        while (k > 0) {
            stk.pop();
            k--;
        }
        string ans(stk.size(), '0');
        for (int i = stk.size() - 1; i >= 0; i--) {
            ans[i] = stk.top();
            stk.pop();
        }
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        return start == ans.size() ? "0" : ans.substr(start);
    }
};
// @lc code=end
