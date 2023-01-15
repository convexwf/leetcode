/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (34.11%)
 * Likes:    807
 * Dislikes: 1734
 * Total Accepted:    82.7K
 * Total Submissions: 242.4K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the n^th digit of the infinite integer sequence
 * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 11
 * Output: 0
 * Explanation: The 11^th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
 * 11, ... is a 0, which is part of the number 10.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
// 2023-01-14 submission
// 71/71 cases passed
// Runtime: 3 ms, faster than 36.1% of C++ online submissions.
// Memory Usage: 6 MB, less than 72.2% of C++ online submissions.
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};
// @lc code=end