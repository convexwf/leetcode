/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
// 1. brute force
// 2024-02-22 submission
// 1101/1101 cases passed
// Runtime: 2 ms, faster than 38.15% of cpp online submissions.
// Memory Usage: 7.4 MB, less than 30.73% of cpp online submissions.
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法
// 2024-02-22 submission
// 1101/1101 cases passed
// Runtime: 2 ms, faster than 38.15% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 8.41% of cpp online submissions.
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
// @lc code=end
