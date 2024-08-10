/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
// 1. Brute force
// 2022-11-14 submission
// 21040/21040 cases passed
// Runtime: 41 ms, faster than 55.67% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 73.1% of cpp online submissions.
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法-整数限制
// 2022-11-14 submission
// 21040/21040 cases passed
// Runtime: 40 ms, faster than 58.38% of cpp online submissions.
// Memory Usage: 6 MB, less than 30.22% of cpp online submissions.
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
};
// @lc code=end

// @lc code=start
// 3. 数学方法-换底公式
// 2022-11-14 submission
// 21040/21040 cases passed
// Runtime: 40 ms, faster than 58.38% of cpp online submissions.
// Memory Usage: 6 MB, less than 14.88% of cpp online submissions.
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};
// @lc code=end
