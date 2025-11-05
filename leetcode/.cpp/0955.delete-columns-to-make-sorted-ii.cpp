/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start
// 1. 贪心算法
// 2024-01-26 submission
// 147/147 cases passed
// Runtime: 3 ms, faster than 97.52% of cpp online submissions.
// Memory Usage: 12.3 MB, less than 6.61% of cpp online submissions.
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        vector<bool> check(m, false); // > true; == false
        int delete_cnt = 0;
        for (int j = 0; j < n; ++j) {
            vector<bool> tmp(m, true);
            bool is_delete = false;
            bool is_seq = true;
            for (int i = 1; i < m; ++i) {
                if (!check[i]) {
                    if (strs[i][j] < strs[i - 1][j]) {
                        is_delete = true;
                        ++delete_cnt;
                        break;
                    }
                    else if (strs[i][j] > strs[i - 1][j]) {
                        tmp[i] = true;
                    }
                    else {
                        tmp[i] = false;
                        is_seq = false;
                    }
                }
            }
            // cout << j << " " << is_delete << " " << is_seq << endl;
            if (is_delete) continue;
            if (is_seq) break;
            check.assign(tmp.begin(), tmp.end());
        }
        return delete_cnt;
    }
};
// @lc code=end
