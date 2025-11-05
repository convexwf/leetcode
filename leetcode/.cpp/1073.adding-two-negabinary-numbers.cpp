/*
 * @lc app=leetcode id=1073 lang=cpp
 *
 * [1073] Adding Two Negabinary Numbers
 */

// @lc code=start
// 1. 模拟
// 2023-11-09 submission
// 267/267 cases passed
// Runtime: 8 ms, faster than 38.49% of cpp online submissions.
// Memory Usage: 19.8 MB, less than 57.14% of cpp online submissions.
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int i = arr1.size() - 1, j = arr2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            carry += (i >= 0 ? arr1[i--] : 0) + (j >= 0 ? arr2[j--] : 0);
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
