/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
// 1. 哈希表
// 2023-10-26 submission
// 89/89 cases passed
// Runtime: 152 ms, faster than 79.8% of cpp online submissions.
// Memory Usage:  MB, less than 68.97% of cpp online submissions.
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
        unordered_map<string, int> mp;
        for (vector<int> &row : matrix) {
            string s;
            int n = row.size();
            int diff = row[0];
            for (int i = 0; i < n; ++i) {
                if (row[i] == diff) {
                    s += '1';
                }
                else {
                    s += '0';
                }
            }
            mp[s]++;
        }
        int ans = 0;
        for (auto &[k, v] : mp) {
            ans = max(ans, v);
        }
        return ans;
    }
};
// @lc code=end
