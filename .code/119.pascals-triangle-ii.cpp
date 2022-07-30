/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (58.68%)
 * Likes:    2931
 * Dislikes: 274
 * Total Accepted:    564.1K
 * Total Submissions: 961.3K
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th (0-indexed) row of the
 * Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 *
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= rowIndex <= 33
 *
 *
 *
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
 * space?
 *
 */

// @lc code=start
// 2022-07-30 submission
// 34/34 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.4 MB, less than 79.99% of C++ online submissions.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret{1};
        for (int num = 1; num < rowIndex + 1; num++) {
            ret.push_back((int64_t)ret.back() * (rowIndex + 1 - num) / num);
        }
        return ret;
    }
};
// @lc code=end