/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
// 1. 模拟+哈希表
// 2023-01-14 submission
// 39/39 cases passed
// Runtime: 4 ms, faster than 41.79% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 37.02% of cpp online submissions.
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string res;

        // check the sign
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            res += '-';
        }
        // check the integer part
        long num = labs(numerator), den = labs(denominator);
        res += to_string(num / den);
        // check the decimal part
        long rem = num % den;
        if (rem == 0) return res;
        res += '.';

        unordered_map<long, int> mp;
        while (rem != 0) {
            if (mp.count(rem)) {
                res.insert(mp[rem], 1, '(');
                res += ')';
                break;
            }
            mp[rem] = res.size();
            rem *= 10;
            res += to_string(rem / den);
            rem %= den;
        }
        return res;
    }
};
// @lc code=end
