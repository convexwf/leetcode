/*
 * @lc app=leetcode id=772 lang=cpp
 *
 * [772] Basic Calculator III
 */

// @lc code=start
// 1. 逆波兰表达式+栈
class Solution {
private:
    int priority(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    vector<string> infixToRPN(const string& s) {
        stack<char> ops;
        vector<string> output;
        string num;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                num += s[i];
            }
            else {
                if (!num.empty()) {
                    output.push_back(num);
                    num.clear();
                }
            }
            if (s[i] == '(') {
                ops.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    output.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.pop();
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                while (!ops.empty() && priority(ops.top()) >= priority(s[i])) {
                    output.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
        if (!num.empty()) output.push_back(num);
        while (!ops.empty()) {
            output.push_back(string(1, ops.top()));
            ops.pop();
        }
        return output;
    }

    int calculateRPN(const vector<string>& output) {
        stack<int> stk;
        for (const string& token : output) {
            if (isdigit(token[0])) {
                stk.push(stoi(token));
            }
            else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if (token == "+") stk.push(a + b);
                if (token == "-") stk.push(a - b);
                if (token == "*") stk.push(a * b);
                if (token == "/") stk.push(a / b);
            }
        }
        return stk.top();
    }

public:
    int calculate(string s) {
        vector<string> output = infixToRPN(s);
        return calculateRPN(output);
    }
};
// @lc code=end
