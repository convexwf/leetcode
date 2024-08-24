/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
// 1. 哈希表+模拟
// 2023-02-18 submission
// 48/48 cases passed
// Runtime: 203 ms, faster than 33.34% of cpp online submissions.
// Memory Usage: 36.9 MB, less than 52% of cpp online submissions.
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }
        vector<int> dirs = {0, 1, 0, -1, 0};
        int x = 0, y = 0, dir = 0, res = 0;
        for (const auto& command : commands) {
            if (command == -2) {
                dir = (dir + 3) % 4;
            }
            else if (command == -1) {
                dir = (dir + 1) % 4;
            }
            else {
                for (int i = 0; i < command; ++i) {
                    int nextX = x + dirs[dir], nextY = y + dirs[dir + 1];
                    if (!obstacleSet.count(to_string(nextX) + "," + to_string(nextY))) {
                        x = nextX;
                        y = nextY;
                        res = max(res, x * x + y * y);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
