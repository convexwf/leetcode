/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

// @lc code=start
// 1. 数学方法
// 2023-12-22 submission
// 59/59 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 29.91% of cpp online submissions.
class Solution {
public:
    string solveEquation(string equation) {
        int a = 0, b = 0, sign = 1, n = equation.size(), digit = 0, op = 1;
        for (int i = 0; i < n; ++i) {
            if (equation[i] == 'x') {
                // 判断是否为 0x
                if (digit == 0 && (i == 0 || equation[i - 1] != '0')) {
                    a += sign * op;
                }
                else {
                    a += sign * op * digit;
                    digit = 0;
                }
            }
            else if (equation[i] == '+' || equation[i] == '-') {
                b += sign * op * digit;
                digit = 0;
                if (equation[i] == '-') {
                    op = -1;
                }
                else {
                    op = 1;
                }
            }
            else if (equation[i] == '=') {
                b += sign * op * digit;
                digit = 0;
                sign = -1;
                op = 1;
            }
            else {
                digit = digit * 10 + equation[i] - '0';
            }
            // cout << "b: " << b << " current digit: " << digit << " now equation[i]" <<
            // equation[i]
            //      << endl;
        }
        b += sign * op * digit;
        if (a == 0 && b == 0) {
            return "Infinite solutions";
        }
        else if (a == 0) {
            return "No solution";
        }
        else {
            return "x=" + to_string(-b / a);
        }
    }
};
// @lc code=end
