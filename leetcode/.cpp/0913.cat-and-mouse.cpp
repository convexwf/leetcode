/*
 * @lc app=leetcode id=913 lang=cpp
 *
 * [913] Cat and Mouse
 */

// @lc code=start
// 1. bfs
// 2025-06-14 submission
// 92/92 cases passed
// Runtime: 559 ms, faster than 24.71% of cpp online submissions.
// Memory Usage:  MB, less than 5.17% of cpp online submissions.
class Solution {
public:
    int catMouseGame(vector<vector<int>> &graph) {
        int n = graph.size();
        const int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2;
        const int MOUSE_TURN = 0, CAT_TURN = 1;
        const int HOLE = 0, MOUSE_START = 1, CAT_START = 2;

        vector<vector<vector<int>>> result(n, vector<vector<int>>(n, vector<int>(2, DRAW)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                degree[i][j][MOUSE_TURN] = graph[i].size();
                degree[i][j][CAT_TURN] = graph[j].size();
            }
            for (int j : graph[HOLE]) {
                --degree[i][j][CAT_TURN];
            }
        }

        function<vector<vector<int>>(int, int, int)> getPreviousStates = [&](int mouse, int cat,
                                                                             int turn) {
            vector<vector<int>> prevStates;
            int previousTurn = (turn == MOUSE_TURN) ? CAT_TURN : MOUSE_TURN;
            if (previousTurn == CAT_TURN) {
                for (int previousCat : graph[cat]) {
                    if (previousCat != HOLE) {
                        prevStates.emplace_back(vector<int>{mouse, previousCat, previousTurn});
                    }
                }
            }
            else {
                for (int previousMouse : graph[mouse]) {
                    prevStates.emplace_back(vector<int>{previousMouse, cat, previousTurn});
                }
            }
            return prevStates;
        };

        queue<vector<int>> q;
        for (int j = 1; j < n; ++j) {
            result[HOLE][j][MOUSE_TURN] = MOUSE_WIN;
            result[HOLE][j][CAT_TURN] = MOUSE_WIN;
            q.push({HOLE, j, MOUSE_TURN});
            q.push({HOLE, j, CAT_TURN});
        }
        for (int i = 1; i < n; ++i) {
            result[i][i][MOUSE_TURN] = CAT_WIN;
            result[i][i][CAT_TURN] = CAT_WIN;
            q.push({i, i, MOUSE_TURN});
            q.push({i, i, CAT_TURN});
        }

        while (!q.empty()) {
            vector<int> state = q.front();
            q.pop();
            int mouse = state[0], cat = state[1], turn = state[2];
            int currentResult = result[mouse][cat][turn];
            for (const vector<int> &prevState : getPreviousStates(mouse, cat, turn)) {
                int prevMouse = prevState[0], prevCat = prevState[1], prevTurn = prevState[2];
                if (result[prevMouse][prevCat][prevTurn] != DRAW) {
                    continue;
                }
                bool anyWin = (currentResult == MOUSE_WIN && prevTurn == MOUSE_TURN) ||
                              (currentResult == CAT_WIN && prevTurn == CAT_TURN);
                if (anyWin) {
                    result[prevMouse][prevCat][prevTurn] = currentResult;
                    q.push({prevMouse, prevCat, prevTurn});
                }
                else {
                    if (--degree[prevMouse][prevCat][prevTurn] == 0) {
                        result[prevMouse][prevCat][prevTurn] = currentResult;
                        q.push({prevMouse, prevCat, prevTurn});
                    }
                }
            }
        }
        return result[MOUSE_START][CAT_START][MOUSE_TURN];
    }
};
