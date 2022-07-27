/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (43.14%)
 * Likes:    4692
 * Dislikes: 4309
 * Total Accepted:    1.3M
 * Total Submissions: 3M
 * Testcase Example:  '[1,2,3]'
 *
 * You are given a large integer represented as an integer array digits, where
 * each digits[i] is the i^th digit of the integer. The digits are ordered from
 * most significant to least significant in left-to-right order. The large
 * integer does not contain any leading 0's.
 *
 * Increment the large integer by one and return the resulting array of
 * digits.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
 *
 *
 * Example 2:
 *
 *
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 *
 *
 * Example 3:
 *
 *
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits does not contain any leading 0's.
 *
 *
 */

// @lc code=start
// 2022-07-27 submission
// 111/111 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 8.8 MB, less than 61.83% of C++ online submissions.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n = digits.size();
        int carry = 1;
        while (n-- > 0) {
            carry += digits[n];
            res.push_back(carry % 10);
            carry /= 10;
        }
        if (carry > 0) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
