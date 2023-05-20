/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
// 1. 递归
// 2023-05-19 submission
// 47/47 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 70.46% of cpp online submissions.
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        else if (n % 2 == 0) {
            return integerReplacement(n / 2) + 1;
        }
        else {
            int a = integerReplacement(n / 2) + 2;
            int b = integerReplacement(n / 2 + 1) + 2;
            return min(a, b);
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 位运算+数学方法
// 2023-05-19 submission
// 47/47 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.1 MB, less than 36.53% of cpp online submissions.
class Solution {
public:
    int integerReplacement(int n) {
        long num = n; // 需要将 n 强制转化为long类型，否则当 n 为 INT_MAX 时会溢出
        int count = 0;
        while (num != 1) {
            if ((num & 1) == 0) { // 偶数
                num >>= 1;        // 等价于 num /= 2;
            }
            // 情况①：最后两位为01；
            // 情况②：最后一位为1且倒数第二位为0
            else if (num == 3 || ((num >> 1) & 1) == 0) {
                num--;
            }
            else { // 最后两位为11
                num++;
            }
            count++;
        }
        return count;
    }
};
// @lc code=end