/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        int a = 0, b = 0, sign = 1, n = equation.size();
        for (int i = 0; i < n; ++i) {
            if (equation[i] == '=') {
                sign = -1;
            } else if (equation[i] == '+' || equation[i] == '-') {
                if (i > 0 && equation[i - 1] == 'x') {
                    a += sign * 1;
                } else {
                    b += sign * stoi(equation.substr(i));
                }
                sign = equation[i] == '+' ? 1 : -1;
            } else if (equation[i] == 'x') {
                if (i > 0 && equation[i - 1] == '0') {
                    continue;
                }
                a += sign * stoi(equation.substr(i - 1, 1));
            }
        }
        if (equation[n - 1] != 'x') {
            b += sign * stoi(equation.substr(n - 1));
        }
        if (a == 0 && b == 0) {
            return "Infinite solutions";
        } else if (a == 0 && b != 0) {
            return "No solution";
        } else {
            return "x=" + to_string(-b / a);
        }
    }
};
// @lc code=end

