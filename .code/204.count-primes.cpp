/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Medium (33.07%)
 * Likes:    5905
 * Dislikes: 1138
 * Total Accepted:    676.1K
 * Total Submissions: 2M
 * Testcase Example:  '10'
 *
 * Given an integer n, return the number of prime numbers that are strictly
 * less than n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 0
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 1
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 5 * 10^6
 * 
 * 
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