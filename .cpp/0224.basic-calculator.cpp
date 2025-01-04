/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
// 1. 栈
// 2023-01-14 submission
// 44/44 cases passed
// Runtime: 5 ms, faster than 94.08% of cpp online submissions.
// Memory Usage: 8 MB, less than 65.38% of cpp online submissions.
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int res = 0, sign = 1, num = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') {
                continue;
            }
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else {
                res += sign * num;
            }
            if (c == '+') {
                sign = 1;
                num = 0;
            }
            else if (c == '-') {
                sign = -1;
                num = 0;
            }
            else if (c == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
                num = 0;
            }
            else if (c == ')') {
                res *= stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
                sign = 1;
                num = 0;
            }
        }
        res += sign * num;
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2023-01-14 submission
// 44/44 cases passed
// Runtime: 110 ms, faster than 5.44% of cpp online submissions.
// Memory Usage: 76.8 MB, less than 5.01% of cpp online submissions.
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1, n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = 10 * num + (c - '0');
            }
            else if (c == '(') {
                int j = i, cnt = 0;
                for (; i < n; ++i) {
                    if (s[i] == '(') ++cnt;
                    if (s[i] == ')') --cnt;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
            if (c == '+' || c == '-' || i == n - 1) {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
        }
        return res;
    }
};
// @lc code=end
