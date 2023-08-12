/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
// 1. 逐位相加
// 2023-08-08 submission
// 152/152 cases passed
// Runtime: 18 ms, faster than 95.72% of cpp online submissions.
// Memory Usage: 28.6 MB, less than 38.2% of cpp online submissions.
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int i = num.size() - 1;
        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i];
            }
            res.push_back(k % 10);
            k /= 10;
            i--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
