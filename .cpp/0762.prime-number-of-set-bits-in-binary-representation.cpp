/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
// 1. 位操作
// 2023-08-30 submission
// 202/202 cases passed
// Runtime: 15 ms, faster than 61.05% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 16.35% of cpp online submissions.
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            int count = 0;
            int n = i;
            while (n) {
                n &= n - 1;
                ++count;
            }
            if (primes.count(count)) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end
