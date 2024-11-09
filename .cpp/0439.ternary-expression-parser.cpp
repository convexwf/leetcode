/*
 * @lc app=leetcode id=439 lang=cpp
 *
 * [439] Ternary Expression Parser
 */

// @lc code=start
// 1. 栈
class Solution {
public:
    string parseTernary(string expression) {
        stack<char> stk;
        for (int i = expression.size() - 1; i >= 0; --i) {
            char c = expression[i];
            if (c == ':') continue;
            if (c == '?') {
                char a = stk.top();
                stk.pop();
                stk.pop();
                char b = stk.top();
                stk.pop();
                stk.push(expression[i - 1] == 'T' ? a : b);
                --i;
            }
            else {
                stk.push(c);
            }
        }
        return string(1, stk.top());
    }
};
// @lc code=end
