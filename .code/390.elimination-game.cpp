/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
// 2020-12-06 submission
// 3377/3377 cases passed
// Runtime: 3 ms, faster than 89.89% of C++ online submissions.
// Memory Usage: 6 MB, less than 47.1% of C++ online submissions.
class Solution {
public:
    int lastRemaining(int n) {
        bool ltor = true;
        int step = 1, cur = 1;
        while (n > 1) {
            if (ltor || n % 2) cur += step;
            step *= 2;
            ltor = not ltor;
            n /= 2;
        }
        return cur;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 3377/3377 cases passed
// Runtime: 7 ms, faster than 60.05% of C++ online submissions.
// Memory Usage: 6 MB, less than 7.77% of C++ online submissions.
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};
// @lc code=end
