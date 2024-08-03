/*
 * @lc app=leetcode id=489 lang=cpp
 *
 * [489] Robot Room Cleaner
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    void cleanRoom(Robot& robot) {
        vector<int> dirs = {0, 1, 0, -1, 0};
        unordered_set<pair<int, int>> visited;
        function<void(int, int, int)> dfs = [&](int x, int y, int dir) {
            robot.clean();
            visited.insert({x, y});
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (!visited.count({nx, ny}) && robot.move()) {
                    dfs(nx, ny, i);
                    robot.turnRight();
                    robot.turnRight();
                    robot.move();
                    robot.turnRight();
                    robot.turnRight();
                }
                robot.turnRight();
            }
        };
        dfs(0, 0, 0);
    }
};
// @lc code=end
