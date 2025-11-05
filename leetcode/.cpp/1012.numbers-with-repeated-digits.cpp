/*
 * @lc app=leetcode id=1012 lang=cpp
 *
 * [1012] Numbers With Repeated Digits
 */

// @lc code=start
// 1. 数学方法+哈希表
// 2025-06-07 submission
// 130/130 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 59.86% of cpp online submissions.
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<int> digits;
        unordered_set<int> used;
        for (int i = n + 1; i > 0; i /= 10) {
            digits.insert(digits.begin(), i % 10);
        }

        int res = 0, len = digits.size();
        for (int i = 1; i < len; ++i) {
            res += 9 * perm(9, i - 1);
        }
        for (int i = 0; i < len; ++i) {
            for (int j = (i == 0 ? 1 : 0); j < digits[i]; ++j) {
                if (used.count(j)) continue;
                res += perm(9 - i, len - i - 1);
            }
            if (used.count(digits[i])) break;
            used.insert(digits[i]);
        }
        return n - res;
    }

    int perm(int n, int k) {
        int res = 1;
        for (int i = 0; i < k; ++i) {
            res *= n - i;
        }
        return res;
    }
};
// @lc code=end
