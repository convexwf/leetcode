/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (32.46%)
 * Likes:    9189
 * Dislikes: 293
 * Total Accepted:    542.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 *
 * Example 2:
 *
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 *
 * Example 3:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 *
 *
 */

// @lc code=start
// 2022-07-28 submission
// 231/231 cases passed
// Runtime: 8 ms, faster than 40.17% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 13.58% of C++ online submissions.
class Solution {
public:
    int longestValidParentheses(string s) {
        s = "^" + s;
        int res = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = (dp[i - 1] + 2);
                dp[i] += dp[i - dp[i]];
                res = max(dp[i], res);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-28 submission
// 231/231 cases passed
// Runtime: 12 ms, faster than 15.97% of C++ online submissions.
// Memory Usage: 6.7 MB, less than 95.8% of C++ online submissions.
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int l = 0, r = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                ++l;
            else
                ++r;
            if (l == r)
                res = max(res, l + r);
            else if (l < r)
                l = r = 0;
        }
        l = r = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(')
                ++l;
            else
                ++r;
            if (l == r)
                res = max(res, l + r);
            else if (l > r)
                l = r = 0;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-28 submission
// 231/231 cases passed
// Runtime: 6 ms, faster than 58.09% of C++ online submissions.
// Memory Usage: 7.2 MB, less than 66.61% of C++ online submissions.
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (st.empty()) {
                    start = i + 1;
                }
                else {
                    st.pop();
                    res = st.empty() ? max(res, i - start + 1)
                                     : max(res, i - st.top());
                }
            }
        }
        return res;
    }
};
// @lc code=end
