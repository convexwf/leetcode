/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
// 1. 位操作-标识位
// 2022-11-15 submission
// 149/149 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 79.43% of cpp online submissions.
class Solution {
public:
    int findComplement(int num) {
        bool start = false;
        for (int i = 31; i >= 0; --i) {
            if (num & (1 << i)) start = true;
            if (start) num ^= (1 << i);
        }
        return num;
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作-mask
// 2022-11-15 submission
// 149/149 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 40.3% of cpp online submissions.
class Solution {
public:
    int findComplement(int num) {
        uint32_t mask = INT_MAX;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};
// @lc code=end

// @lc code=start
// 3. 递归
// 2022-11-15 submission
// 149/149 cases passed
// Runtime: 5 ms, faster than 18.29% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 79.43% of cpp online submissions.
class Solution {
public:
    int findComplement(int num) {
        return (1 - num % 2) + 2 * (num <= 1 ? 0 : findComplement(num / 2));
    }
};
// @lc code=end
