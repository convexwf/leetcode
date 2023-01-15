/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 *
 * https://leetcode.com/problems/dungeon-game/description/
 *
 * algorithms
 * Hard (36.96%)
 * Likes:    4441
 * Dislikes: 83
 * Total Accepted:    181.1K
 * Total Submissions: 490K
 * Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
 *
 * The demons had captured the princess and imprisoned her in the bottom-right
 * corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D
 * grid. Our valiant knight was initially positioned in the top-left room and
 * must fight his way through dungeon to rescue the princess.
 * 
 * The knight has an initial health point represented by a positive integer. If
 * at any point his health point drops to 0 or below, he dies immediately.
 * 
 * Some of the rooms are guarded by demons (represented by negative integers),
 * so the knight loses health upon entering these rooms; other rooms are either
 * empty (represented as 0) or contain magic orbs that increase the knight's
 * health (represented by positive integers).
 * 
 * To reach the princess as quickly as possible, the knight decides to move
 * only rightward or downward in each step.
 * 
 * Return the knight's minimum initial health so that he can rescue the
 * princess.
 * 
 * Note that any room can contain threats or power-ups, even the first room the
 * knight enters and the bottom-right room where the princess is imprisoned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
 * Output: 7
 * Explanation: The initial health of the knight must be at least 7 if he
 * follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dungeon = [[0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == dungeon.length
 * n == dungeon[i].length
 * 1 <= m, n <= 200
 * -1000 <= dungeon[i][j] <= 1000
 * 
 * 
 */

// @lc code=start
// 2023-01-14 submission
// 45/45 cases passed
// Runtime: 8 ms, faster than 72.13% of C++ online submissions.
// Memory Usage: 9 MB, less than 20.57% of C++ online submissions.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 45/45 cases passed
// Runtime: 3 ms, faster than 97.82% of C++ online submissions.
// Memory Usage: 8.8 MB, less than 75.73% of C++ online submissions.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0];
    }
};
// @lc code=end