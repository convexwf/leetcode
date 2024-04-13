/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
// 1. 栈
// 2023-09-13 submission
// 86/86 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 43.23% of cpp online submissions.
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        for (char c : s) {
            if (c == '(') {
                stk.push(0);
            }
            else {
                int cur = 0;
                while (stk.top() != 0) {
                    cur += stk.top();
                    stk.pop();
                }
                stk.pop();
                stk.push(cur == 0 ? 1 : cur * 2);
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 栈优化
// 2023-09-13 submission
// 86/86 cases passed
// Runtime: 2 ms, faster than 45.21% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 11.92% of cpp online submissions.
class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0, level = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                ++level;
            else {
                --level;
                if (s[i - 1] == '(') res += 1 << level;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 栈-另一种思路
// 2023-09-13 submission
// 86/86 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 11.92% of cpp online submissions.
class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        stack<int> st;
        for (char c : s) {
            if (c == '(') {
                st.push(res);
                res = 0;
            }
            else {
                res = st.top() + max(res * 2, 1);
                st.pop();
            }
        }
        return res;
    }
};
// @lc code=end
