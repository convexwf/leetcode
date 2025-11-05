/*
 * @lc app=leetcode id=533 lang=cpp
 *
 * [533] Lonely Pixel II
 */

// @lc code=start
// 1. 计数+邻接表
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size(), n = picture[0].size();
        vector<int> rows(m, 0);
        vector<unordered_set<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    adj[j].insert(i);
                }
            }
        }
        int res = 0;
        for (int j = 0; j < n; ++j) {
            int r = -1;
            for (int i : adj[j]) {
                if (rows[i] == target) {
                    if (r == -1) {
                        r = i;
                    }
                    else if (picture[r] != picture[i]) {
                        r = -2;
                        break;
                    }
                }
            }
            if (r >= 0) {
                res += target;
            }
        }
        return res;
    }
};
// @lc code=end
