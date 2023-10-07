/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
// 2022-07-30 submission
// 601/601 cases passed
// Runtime: 10 ms, faster than 8.38% of C++ online submissions.
// Memory Usage: 6 MB, less than 47.87% of C++ online submissions.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while (n > 0) {
            num++;
            n &= n - 1;
        }
        return num;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-30 submission
// 601/601 cases passed
// Runtime: 8 ms, faster than 8.38% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 78.98% of C++ online submissions.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res += (n & 1);
            n = n >> 1;
        }
        return res;
    }
};
// @lc code=end