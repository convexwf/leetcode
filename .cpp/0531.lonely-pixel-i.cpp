/*
 * @lc app=leetcode id=531 lang=cpp
 *
 * [531] Lonely Pixel I
 */

// @lc code=start
// 1. 计数
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++row[i];
                    ++col[j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    ++res;
                }
            }
        }
        return res;
    }
};
// @lc code=end
