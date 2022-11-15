/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (34.03%)
 * Likes:    6049
 * Dislikes: 499
 * Total Accepted:    361K
 * Total Submissions: 1.1M
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number and return it.
 * 
 * Since the result may be very large, so you need to return a string instead
 * of an integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,2]
 * Output: "210"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
// 2022-11-14 submission
// 230/230 cases passed
// Runtime: 43 ms, faster than 8.07% of C++ online submissions.
// Memory Usage: 11 MB, less than 87.69% of C++ online submissions.
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
           return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res[0] == '0' ? "0" : res;
    }
};
// @lc code=end