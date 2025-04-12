/*
 * @lc app=leetcode id=750 lang=cpp
 *
 * [750] Number Of Corner Rectangles
 */

// @lc code=start
// 1. 枚举+哈希表
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        unordered_map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int k = j + 1; k < n; ++k) {
                        if (grid[i][k] == 1) {
                            ans += mp[{j, k}];
                            mp[{j, k}]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
