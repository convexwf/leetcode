/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
// 1. 动态规划
// 2022-07-28 submission
// 231/231 cases passed
// Runtime: 3 ms, faster than 72.51% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 22.34% of cpp online submissions.
class Solution {
public:
    int longestValidParentheses(string s) {
        s = "^" + s;
        int res = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                res = max(dp[i], res);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 计数
// 2022-07-28 submission
// 231/231 cases passed
// Runtime: 12 ms, faster than 15.97% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 95.8% of cpp online submissions.
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int l = 0, r = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++l;
            }
            else {
                ++r;
            }
            if (l == r) {
                res = max(res, l + r);
            }
            else if (l < r) {
                l = r = 0;
            }
        }
        l = r = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++l;
            }
            else {
                ++r;
            }
            if (l == r) {
                res = max(res, l + r);
            }
            else if (l > r) {
                l = r = 0;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 栈
// 2022-07-28 submission
// 231/231 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 46.47% of cpp online submissions.
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                else {
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};
// @lc code=end
