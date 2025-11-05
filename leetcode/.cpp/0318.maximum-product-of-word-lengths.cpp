/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
// 1. 位操作
// 2024-08-05 submission
// 168/168 cases passed
// Runtime: 47 ms, faster than 70.28% of cpp online submissions.
// Memory Usage: 25.9 MB, less than 52.17% of cpp online submissions.
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n);
        vector<int> len(n);
        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
            len[i] = words[i].size();
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    res = max(res, len[i] * len[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
