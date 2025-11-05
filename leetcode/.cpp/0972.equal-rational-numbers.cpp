/*
 * @lc app=leetcode id=972 lang=cpp
 *
 * [972] Equal Rational Numbers
 */

// @lc code=start
// 1. 字符串处理+数学方法
// 2025-03-04 submission
// 74/74 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 5.17% of cpp online submissions.
class Solution {
public:
    bool isRationalEqual(string s, string t) {
        vector<int> s_fraction = parseFraction(getParts(s));
        vector<int> t_fraction = parseFraction(getParts(t));
        return s_fraction == t_fraction;
    }

    vector<string> getParts(const string& s) {
        vector<string> parts(3, "");
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.' || s[i] == '(') {
                idx++;
            }
            else if (s[i] != ')') {
                parts[idx] += s[i];
            }
        }
        return parts;
    }

    vector<int> parseFraction(const vector<string>& parts) {
        int integer = stoi(parts[0]);
        const string decimal = parts[1] + parts[2];
        const string nonRepeating = parts[1];

        int m = decimal.length();
        int n = nonRepeating.length();
        int a = (m == 0) ? 0 : stoi(decimal);
        int b = (n == 0) ? 0 : stoi(nonRepeating);

        // repeating part not exist
        if (m == n) {
            int numerator = a;
            int denominator = pow(10, m);
            int gcd = __gcd(numerator, denominator);
            return {integer, numerator / gcd, denominator / gcd};
        }

        int numerator = a - b;
        int denominator = pow(10, m) - pow(10, n);
        int gcd = __gcd(numerator, denominator);

        if (numerator == denominator) {
            return {integer + 1, 0, 1};
        }

        return {integer, numerator / gcd, denominator / gcd};
    }
};
// @lc code=end
