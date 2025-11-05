/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */

// @lc code=start
// 1. 数学方法
// 2025-03-05 submission
// 70/70 cases passed
// Runtime: 23 ms, faster than 15.97% of cpp online submissions.
// Memory Usage: 15.9 MB, less than 8.37% of cpp online submissions.
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> s;
        int n = 1, len = 1;
        while (len <= k) {
            if (n % k == 0) {
                return len;
            }
            if (s.count(n % k)) {
                return -1;
            }
            s.insert(n % k);
            n = (n * 10 + 1) % k;
            len++;
        }
        return -1;
    }
};
// @lc code=end
