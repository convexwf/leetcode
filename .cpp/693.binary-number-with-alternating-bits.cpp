/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
// 2022-11-17 submission
// 204/204 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 69.74% of C++ online submissions.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int d = n & 1;
        while ((n & 1) == d) {
            d ^= 1;
            n >>= 1;
        }
        return n == 0;
    }
};
// @lc code=end

// @lc code=start
// 2021-12-23 submission
// 204/204 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 62.97% of C++ online submissions.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = ((n >> 1) ^ n);
        return (x & (x + 1)) == 0;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 204/204 cases passed
// Runtime: 3 ms, faster than 39.85% of C++ online submissions.
// Memory Usage: 6 MB, less than 28.41% of C++ online submissions.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return ((n ^= n / 4) & (n - 1)) == 0;
    }
};
// @lc code=end