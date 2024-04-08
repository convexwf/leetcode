/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
// 2022-08-27 submission
// 87/87 cases passed
// Runtime: 363 ms, faster than 31.88% of cpp online submissions.
// Memory Usage: 10.3 MB, less than 51.86% of cpp online submissions.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> res(n, 1);
        vector<int> idx(primes.size(), 0);

        for (int i = 1; i < n; i++) {
            long long min_val = primes[0] * res[idx[0]];
            for (int j = 1; j < primes.size(); j++) {
                min_val = min(primes[j] * res[idx[j]], min_val);
            }
            for (int j = 0; j < primes.size(); j++) {
                if (min_val == primes[j] * res[idx[j]]) idx[j]++;
            }
            res[i] = min_val;
        }
        return res.back();
    }
};
// @lc code=end
