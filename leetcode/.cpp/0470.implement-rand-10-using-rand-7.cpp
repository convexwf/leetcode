/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 */

// @lc code=start
// 1. 拒绝采样
// 2022-08-19 submission
// 12/12 cases passed
// Runtime: 70 ms, faster than 78.6% of cpp online submissions.
// Memory Usage: 7.5 MB, less than 17.27% of cpp online submissions.

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution {
public:
    int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) return num % 10 + 1;
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 拒绝采样-递归
// 2022-08-19 submission
// 12/12 cases passed
// Runtime: 136 ms, faster than 6.83% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 17.27% of cpp online submissions.
class Solution {
public:
    int rand10() {
        int num = (rand7() - 1) * 7 + rand7();
        return (num <= 40) ? (num % 10 + 1) : rand10();
    }
};
// @lc code=end

// @lc code=start
// 3. 拒绝采样-进一步优化
// 2022-08-19 submission
// 12/12 cases passed
// Runtime: 103 ms, faster than 37.05% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 86.15% of cpp online submissions.
class Solution {
public:
    int rand10() {
        while (true) {
            int a = rand7(), b = rand7();
            int num = (a - 1) * 7 + b;
            if (num <= 40) return num % 10 + 1;
            a = num - 40, b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 60) return num % 10 + 1;
            a = num - 60, b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 20) return num % 10 + 1;
        }
    }
};
// @lc code=end
