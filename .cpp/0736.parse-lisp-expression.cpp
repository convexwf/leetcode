/*
 * @lc app=leetcode id=736 lang=cpp
 *
 * [736] Parse Lisp Expression
 */

// @lc code=start
// 1. 栈+字符串处理+哈希表
// 2025-06-04 submission
// 66/66 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 12.6 MB, less than 70.8% of cpp online submissions.
class Solution {
public:
    int evaluate(string expression) {
        int cur = 0;
        unordered_map<string, vector<int>> scope;

        function<string()> parseVar = [&]() {
            int j = cur;
            while (cur < expression.size() && expression[cur] != ' ' && expression[cur] != ')')
                ++cur;
            return expression.substr(j, cur - j);
        };
        function<int()> parseInt = [&]() {
            int sign = 1, v = 0;
            if (expression[cur] == '-') {
                sign = -1;
                ++cur;
            }
            while (cur < expression.size() && isdigit(expression[cur])) {
                v = v * 10 + (expression[cur] - '0');
                ++cur;
            }
            return sign * v;
        };
        function<int()> eval = [&]() {
            if (expression[cur] != '(') {
                return islower(expression[cur]) ? scope[parseVar()].back() : parseInt();
            }
            int ans = 0;
            ++cur;
            if (expression[cur] == 'l') {
                cur += 4; // skip "let "
                vector<string> vars;
                while (true) {
                    string var = parseVar();
                    if (expression[cur] == ')') {
                        ans = scope[var].back();
                        break;
                    }
                    ++cur; // skip space
                    vars.push_back(var);
                    scope[var].push_back(eval());
                    ++cur; // skip space or next expression
                    if (!islower(expression[cur])) {
                        ans = eval();
                        break;
                    }
                }
                for (string v : vars) {
                    scope[v].pop_back();
                }
            }
            else {
                bool add = expression[cur] == 'a';
                cur += add ? 4 : 5; // skip "add " or "mult "
                int a = eval();
                ++cur; // skip space
                int b = eval();
                ans = add ? a + b : a * b;
            }
            ++cur; // skip ')'
            return ans;
        };
        return eval();
    }
};
// @lc code=end
