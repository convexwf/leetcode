/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
// 1. 直接计算
// 2023-07-20 submission
// 24/24 cases passed
// Runtime: 13 ms, faster than 43.71% of cpp online submissions.
// Memory Usage: 13.9 MB, less than 62.87% of cpp online submissions.
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int prefix = 0;
        for (int i = 0; i < A.size(); ++i) {
            prefix = ((prefix << 1) + A[i]) % 5;
            ans.push_back(prefix == 0);
        }
        return ans;
    }
};
// @lc code=end
