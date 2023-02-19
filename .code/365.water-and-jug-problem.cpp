/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 *
 * https://leetcode.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (37.19%)
 * Likes:    1112
 * Dislikes: 1307
 * Total Accepted:    77.3K
 * Total Submissions: 207.9K
 * Testcase Example:  '3\n5\n4'
 *
 * You are given two jugs with capacities jug1Capacity and jug2Capacity liters.
 * There is an infinite amount of water supply available. Determine whether it
 * is possible to measure exactly targetCapacity liters using these two jugs.
 * 
 * If targetCapacity liters of water are measurable, you must have
 * targetCapacity liters of water contained within one or both buckets by the
 * end.
 * 
 * Operations allowed:
 * 
 * 
 * Fill any of the jugs with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full,
 * or the first jug itself is empty.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
 * Output: true
 * Explanation: The famous Die Hard example 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= jug1Capacity, jug2Capacity, targetCapacity <= 10^6
 * 
 * 
 */

// @lc code=start
// 2023-02-13 submission
// 28/28 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 87.84% of C++ online submissions.
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};
// @lc code=end