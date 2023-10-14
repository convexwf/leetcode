/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
// 1. BFS
// 2023-10-13 submission
// 215/215 cases passed
// Runtime: 13 ms, faster than 73.05% of cpp online submissions.
// Memory Usage: 12.7 MB, less than 91.57% of cpp online submissions.
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int step = 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize-- > 0) {
                int num = q.front();
                q.pop();
                for (int i = 1; i <= 6; ++i) {
                    int next = num + i;
                    // 终点存在梯子
                    if (next >= n * n) {
                        return step + 1;
                    }
                    pair<int, int> pos = getPos(next, n);
                    if (board[pos.first][pos.second] != -1) {
                        next = board[pos.first][pos.second];
                    }
                    // 存在到达终点的梯子
                    if (next >= n * n) {
                        return step + 1;
                    }
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            ++step;
        }
        return -1;
    }

    pair<int, int> getPos(const int& num, const int& n) {
        int row = (num - 1) / n;
        int col = (num - 1) % n;
        if (row % 2 == 1) {
            col = n - 1 - col;
        }
        row = n - 1 - row;
        return {row, col};
    }
};
// @lc code=end
