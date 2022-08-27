/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (74.70%)
 * Likes:    3223
 * Dislikes: 202
 * Total Accepted:    489.3K
 * Total Submissions: 655K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, return the Hamming distance between them.
 *
 *
 * Example 1:
 *
 *
 * Input: x = 1, y = 4
 * Output: 2
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * The above arrows point to positions where the corresponding bits are
 * different.
 *
 *
 * Example 2:
 *
 *
 * Input: x = 3, y = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= x, y <= 2^31 - 1
 *
 *
 */

// @lc code=start
// 2022-08-26 submission
// 149/149 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 26.57% of C++ online submissions.
class Solution {
public:
    int hammingDistance(int x, int y) {
        int merge = x ^ y;
        int res = 0;
        while (merge > 0) {
            ++res;
            merge = merge & (merge - 1);
        }
        return res;
    }
};
// @lc code=end