/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (51.67%)
 * Likes:    1171
 * Dislikes: 1358
 * Total Accepted:    113.5K
 * Total Submissions: 219.7K
 * Testcase Example:  '2'
 *
 * Given an integer n, return the count of all numbers with unique digits, x,
 * where 0 <= x < 10^n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 91
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100, excluding 11,22,33,44,55,66,77,88,99
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 8
 *
 *
 */

// @lc code=start
// 2020-11-13 submission
// 9/9 cases passed
// Runtime: 3 ms, faster than 46.29% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 85.86% of C++ online submissions.
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 0;
        int cur = 1;
        for (int i = 1, j = 10; i <= n; i++, j--) {
            cur *= min(9, max(0, j));
            res += cur;
        }
        return res + 1;
    }
    // 另一种写法
    // int countNumbersWithUniqueDigits(int n) {
    //     if (n == 0) return 1;
    //     int res = 10, cnt = 9;
    //     for (int i = 2; i <= n; ++i) {
    //         cnt *= (11 - i);
    //         res += cnt;
    //     }
    //     return res;
    // }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 9/9 cases passed
// Runtime: 86 ms, faster than 5.47% of C++ online submissions.
// Memory Usage: 6.2 MB, less than 15.85% of C++ online submissions.
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1, max = pow(10, n), used = 0;
        for (int i = 1; i < 10; ++i) {
            used |= (1 << i);
            res += search(i, max, used);
            used &= ~(1 << i);
        }
        return res;
    }
    int search(int pre, int max, int used) {
        int res = 0;
        if (pre < max) ++res;
        else return res;
        for (int i = 0; i < 10; ++i) {
            if (!(used & (1 << i))) {
                used |= (1 << i);
                int cur = 10 * pre + i;
                res += search(cur, max, used);
                used &= ~(1 << i);
            }
        }
        return res;
    }
};
// @lc code=end
