/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
// 2022-11-14 submission
// 66/66 cases passed
// Runtime: 276 ms, faster than 53.59% of C++ online submissions.
// Memory Usage: 10.4 MB, less than 28.18% of C++ online submissions.
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n, true);
        for (int i = 2; i < n; ++i) {
            if (!prime[i]) continue;
            ++res;
            for (int j = 2; i * j < n; ++j) {
                prime[i * j] = false;
            }
        }
        return res;
    }
};
// @lc code=end