/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
// 1. 模拟
// 2024-01-04 submission
// 86/86 cases passed
// Runtime: 30 ms, faster than 91.91% of cpp online submissions.
// Memory Usage: 12.5 MB, less than 78.13% of cpp online submissions.
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
