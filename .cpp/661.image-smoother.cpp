/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
// 2022-11-15 submission
// 203/203 cases passed
// Runtime: 746 ms, faster than 5.48% of C++ online submissions.
// Memory Usage: 81.5 MB, less than 6.3% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return {};
        int m = M.size(), n = M[0].size();
        vector<vector<int>> res = M;
        vector<vector<int>> dirs{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = M[i][j], all = 1;
                for (vector<int> dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    ++all;
                    cnt += M[x][y];
                }
                res[i][j] = cnt / all;
            }
        }
        return res;
    }
};
// @lc code=end