/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
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
