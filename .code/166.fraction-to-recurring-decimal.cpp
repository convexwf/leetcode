/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (23.85%)
 * Likes:    1688
 * Dislikes: 3118
 * Total Accepted:    190.5K
 * Total Submissions: 798.7K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * If multiple answers are possible, return any of them.
 * 
 * It is guaranteed that the length of the answer string is less than 10^4 for
 * all the given inputs.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 4, denominator = 333
 * Output: "0.(012)"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= numerator, denominator <= 2^31 - 1
 * denominator != 0
 * 
 * 
 */

// @lc code=start
// 2023-01-14 submission
// 39/39 cases passed
// Runtime: 4 ms, faster than 41.79% of C++ online submissions.
// Memory Usage: 6.4 MB, less than 37.02% of C++ online submissions.
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;
        string res = to_string(out);
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
        if (rem == 0) return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            ++pos;
        }
        return res + s;
    }
};
// @lc code=end