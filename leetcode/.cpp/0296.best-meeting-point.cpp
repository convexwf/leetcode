/*
 * @lc app=leetcode id=296 lang=cpp
 *
 * [296] Best Meeting Point
 */

// @lc code=start
// 1. 排序+中位数
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x, y;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int res = 0;
        for (int i = 0, j = x.size() - 1; i < j; ++i, --j) {
            res += x[j] - x[i] + y[j] - y[i];
        }
        return res;
    }
};
// @lc code=end
