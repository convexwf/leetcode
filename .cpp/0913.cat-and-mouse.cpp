/*
 * @lc app=leetcode id=913 lang=cpp
 *
 * [913] Cat and Mouse
 */

// @lc code=start
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        function<int(int, int, int)> dfs = [&](int mouse, int cat, int turn) {
            if (turn == 0) {              // Mouse's turn
                if (mouse == 0) return 1; // Mouse wins
                if (dp[mouse][cat][turn] != -1) return dp[mouse][cat][turn];

                for (int next : graph[mouse]) {
                    if (dfs(next, cat, 1 - turn) == 1) {
                        return dp[mouse][cat][turn] = 1; // Mouse can win
                    }
                }
                return dp[mouse][cat][turn] = 2; // Cat wins
            }
            else {                          // Cat's turn
                if (cat == mouse) return 2; // Cat wins
                if (dp[mouse][cat][turn] != -1) return dp[mouse][cat][turn];

                for (int next : graph[cat]) {
                    if (next != 0 && dfs(mouse, next, 1 - turn) == 2) {
                        return dp[mouse][cat][turn] = 2; // Cat can win
                    }
                }
                return dp[mouse][cat][turn] = 0; // Draw
            }
        };

        return dfs(1, 2, 0);
    }
};
// @lc code=end
