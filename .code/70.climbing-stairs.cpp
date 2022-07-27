/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (51.44%)
 * Likes:    13079
 * Dislikes: 391
 * Total Accepted:    1.7M
 * Total Submissions: 3.3M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 45
 *
 *
 */

// @lc code=start
// 2022-07-27 submission
// 45/45 cases passed
// Runtime: 4 ms, faster than 22.52% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 83.64% of C++ online submissions.
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 0; i < n - 1; i++) {
            b += a;
            a = b - a;
        }
        return b;
    }
};
// @lc code=end
