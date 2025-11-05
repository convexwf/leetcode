/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
// 1. 位操作
// 2022-11-14 submission
// 1061/1061 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 26.13% of cpp online submissions.
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};
// @lc code=end

// @lc code=start
// 2. 循环
// 2024-06-24 submission
// 1063/1063 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 36.85% of cpp online submissions.
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};
// @lc code=end

// @lc code=start
// 3. 换底公式
// 2024-06-24 submission
// 1063/1063 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.4 MB, less than 11.34% of cpp online submissions.
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (log10(n) / log10(4) - int(log10(n) / log10(4)) == 0);
    }
};
// @lc code=end

// @lc code=start
// 4. 判断 n 是否能被 3 整除
// 2024-06-24 submission
// 1063/1063 cases passed
// Runtime: 5 ms, faster than 22.3% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 36.85% of cpp online submissions.
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};
// @lc code=end
