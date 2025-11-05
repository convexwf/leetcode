/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start
// 1. 最大公约数
// 2023-06-27 submission
// 105/105 cases passed
// Runtime: 4 ms, faster than 41.62% of cpp online submissions.
// Memory Usage:  MB, less than 73.29% of cpp online submissions.
class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;
        istringstream in(expression);
        char slash;
        int n, d;
        while (in >> n >> slash >> d) {
            numerator = numerator * d + denominator * n;
            denominator *= d;
            int gcdValue = abs(gcd(numerator, denominator));
            numerator /= gcdValue;
            denominator /= gcdValue;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
// @lc code=end
