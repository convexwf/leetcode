/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        int i = 1, j = 0, ans = 0;
        while (i < m && j < n) {
            if (strs[i][j] < strs[i - 1][j]) {
                ++ans;
                ++j;
                i = 1;
            }
            else if (strs[i][j] == strs[i - 1][j]) {
                ++i;
            }
            else {
                ++j;
                i = 1;
            }
        }
    }
};
// @lc code=end
