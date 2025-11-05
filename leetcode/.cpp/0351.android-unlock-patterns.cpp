/*
 * @lc app=leetcode id=351 lang=cpp
 *
 * [351] Android Unlock Patterns
 */

// @lc code=start
// 1. 分类讨论+dfs
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] =
            skip[6][4] = 5;
        vector<bool> visited(10, false);
        visited[0] = true;
        int res = 0;
        res += dfs(1, 1, m, n, skip, visited) * 4;
        res += dfs(2, 1, m, n, skip, visited) * 4;
        res += dfs(5, 1, m, n, skip, visited);
        return res;
    }

    int dfs(int i, int choose, int m, int n, vector<vector<int>>& skip, vector<bool>& visited) {
        if (choose >= m) {
            ++choose;
        }
        if (choose == n) {
            return 1;
        }
        visited[i] = true;
        int res = 0;
        for (int j = 1; j <= 9; ++j) {
            if (!visited[j] && visited[skip[i][j]]) {
                res += dfs(j, choose + 1, m, n, skip, visited);
            }
        }
        visited[i] = false;
        return res;
    }
};
// @lc code=end
