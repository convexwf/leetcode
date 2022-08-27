/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (45.86%)
 * Likes:    1653
 * Dislikes: 310
 * Total Accepted:    109.8K
 * Total Submissions: 239.4K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * A super ugly number is a positive integer whose prime factors are in the
 * array primes.
 *
 * Given an integer n and an array of integers primes, return the n^th super
 * ugly number.
 *
 * The n^th super ugly number is guaranteed to fit in a 32-bit signed
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12 super ugly numbers given primes = [2,7,13,19].
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, primes = [2,3,5]
 * Output: 1
 * Explanation: 1 has no prime factors, therefore all of its prime factors are
 * in the array primes = [2,3,5].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^5
 * 1 <= primes.length <= 100
 * 2 <= primes[i] <= 1000
 * primes[i] is guaranteed to be a prime number.
 * All the values of primes are unique and sorted in ascending order.
 *
 *
 */

// @lc code=start
// 2022-08-27 submission
// 87/87 cases passed
// Runtime: 363 ms, faster than 31.88% of C++ online submissions.
// Memory Usage: 10.3 MB, less than 51.86% of C++ online submissions.
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