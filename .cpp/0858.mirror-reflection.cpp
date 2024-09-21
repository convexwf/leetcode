/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */

// @lc code=start
// 1. 数学方法+分类讨论
// 2024-09-18 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 19.23% of cpp online submissions.
// Memory Usage: 7.5 MB, less than 47.86% of cpp online submissions.
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int k = 1;
        while (k * q % p != 0) {
            k++;
        }
        cout << p << " " << q << " " << k << endl;
        if (k % 2 == 1) {
            return (k * q % (2 * p) == 0) ? 0 : 1;
        }
        else {
            return (k * q % (2 * p) == 0) ? -1 : 2;
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法+优化
// 2024-09-18 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 19.23% of cpp online submissions.
// Memory Usage: 7.5 MB, less than 47.86% of cpp online submissions.
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int k = p / __gcd(p, q);
        if (k % 2 == 1) {
            return (k * q % (2 * p) == 0) ? 0 : 1;
        }
        else {
            return (k * q % (2 * p) == 0) ? -1 : 2;
        }
    }
};
// @lc code=end
