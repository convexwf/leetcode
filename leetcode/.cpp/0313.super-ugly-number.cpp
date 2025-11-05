/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
// 1. 多指针+动态规划
// 2022-08-27 submission
// 87/87 cases passed
// Runtime: 363 ms, faster than 31.88% of cpp online submissions.
// Memory Usage: 10.3 MB, less than 51.86% of cpp online submissions.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> res(n, 1);
        vector<int> idx(primes.size(), 0);

        for (int i = 1; i < n; i++) {
            long min_val = primes[0] * res[idx[0]];
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

// @lc code=start
// 2. 最小堆
// 2024-05-24 submission
// 87/87 cases passed
// Runtime: 442 ms, faster than 14.04% of cpp online submissions.
// Memory Usage: 327.7 MB, less than 9.89% of cpp online submissions.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        for (int i = 1; i < n; i++) {
            long t = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == t) {
                pq.pop();
            }
            for (int prime : primes) {
                pq.push(t * prime);
            }
        }
        return pq.top();
    }
};
// @lc code=end
