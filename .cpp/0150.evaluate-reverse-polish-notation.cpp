/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
// 1. 栈
// 2022-08-10 submission
// 20/20 cases passed
// Runtime: 4 ms, faster than 98.71% of cpp online submissions.
// Memory Usage: 11.9 MB, less than 89.14% of cpp online submissions.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                stk.push(stoi(token));
            }
            else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if (token == "+")
                    stk.push(a + b);
                else if (token == "-")
                    stk.push(a - b);
                else if (token == "*")
                    stk.push(a * b);
                else
                    stk.push(a / b);
            }
        }
        return stk.top();
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 21/21 cases passed
// Runtime: 14 ms, faster than 51.5% of cpp online submissions.
// Memory Usage: 13.3 MB, less than 5.24% of cpp online submissions.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int op = (int)tokens.size() - 1;
        return helper(tokens, op);
    }
    int helper(vector<string>& tokens, int& op) {
        string str = tokens[op];
        if (str != "+" && str != "-" && str != "*" && str != "/") return stoi(str);
        int num1 = helper(tokens, --op);
        int num2 = helper(tokens, --op);
        if (str == "+") return num2 + num1;
        if (str == "-") return num2 - num1;
        if (str == "*") return num2 * num1;
        return num2 / num1;
    }
};
// @lc code=end
