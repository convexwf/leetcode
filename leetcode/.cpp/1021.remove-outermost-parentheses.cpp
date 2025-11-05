/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
// 1. 栈
// 2024-01-05 submission
// 59/59 cases passed
// Runtime: 5 ms, faster than 38.87% of cpp online submissions.
// Memory Usage: 7.1 MB, less than % of cpp online submissions.
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> stk;
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
            }
            else {
                stk.pop();
                if (stk.empty()) {
                    res += s.substr(last + 1, i - last - 1);
                    last = i + 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 计数
// 2024-01-05 submission
// 59/59 cases passed
// Runtime: 4 ms, faster than 54.19% of cpp online submissions.
// Memory Usage: 7.1 MB, less than % of cpp online submissions.
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int cnt = 0;
        for (char c : s) {
            if (c == '(' && cnt++ > 0) res += c;
            if (c == ')' && cnt-- > 1) res += c;
        }
        return res;
    }
};
// @lc code=end
