/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 *
 * https://leetcode.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Medium (38.74%)
 * Likes:    147
 * Dislikes: 23
 * Total Accepted:    35.7K
 * Total Submissions: 92.2K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * A robot on an infinite XY-plane starts at point (0, 0) facing north. The
 * robot can receive a sequence of these three possible types of
 * commands:
 *
 *
 * -2: Turn left 90 degrees.
 * -1: Turn right 90 degrees.
 * 1 <= k <= 9: Move forward k units, one unit at a time.
 *
 *
 * Some of the grid squares are obstacles. The i^th obstacle is at grid point
 * obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will
 * instead stay in its current location and move on to the next command.
 *
 * Return the maximum Euclidean distance that the robot ever gets from the
 * origin squared (i.e. if the distance is 5, return 25).
 *
 * Note:
 *
 *
 * North means +Y direction.
 * East means +X direction.
 * South means -Y direction.
 * West means -X direction.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: commands = [4,-1,3], obstacles = []
 * Output: 25
 * Explanation: The robot starts at (0, 0):
 * 1. Move north 4 units to (0, 4).
 * 2. Turn right.
 * 3. Move east 3 units to (3, 4).
 * The furthest point the robot ever gets from the origin is (3, 4), which
 * squared is 3^2 + 4^2 = 25 units away.
 *
 *
 * Example 2:
 *
 *
 * Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * Output: 65
 * Explanation: The robot starts at (0, 0):
 * 1. Move north 4 units to (0, 4).
 * 2. Turn right.
 * 3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at
 * (1, 4).
 * 4. Turn left.
 * 5. Move north 4 units to (1, 8).
 * The furthest point the robot ever gets from the origin is (1, 8), which
 * squared is 1^2 + 8^2 = 65 units away.
 *
 *
 * Example 3:
 *
 *
 * Input: commands = [6,-1,-1,6], obstacles = []
 * Output: 36
 * Explanation: The robot starts at (0, 0):
 * 1. Move north 6 units to (0, 6).
 * 2. Turn right.
 * 3. Turn right.
 * 4. Move south 6 units to (0, 0).
 * The furthest point the robot ever gets from the origin is (0, 6), which
 * squared is 6^2 = 36 units away.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= commands.length <= 10^4
 * commands[i] is either -2, -1, or an integer in the range [1, 9].
 * 0 <= obstacles.length <= 10^4
 * -3 * 10^4 <= xi, yi <= 3 * 10^4
 * The answer is guaranteed to be less than 2^31.
 *
 *
 */

// @lc code=start
// 2023-02-18 submission
// 48/48 cases passed
// Runtime: 203 ms, faster than 33.34% of C++ online submissions.
// Memory Usage: 36.9 MB, less than 52% of C++ online submissions.
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> m_obs;
        for (vector<int> point : obstacles) {
            string pattern = to_string(point[0]) + "_" + to_string(point[1]);
            m_obs.insert(pattern);
        }
        vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int idx = 0, curX = 0, curY = 0, res = 0;
        for (int command : commands) {
            if (command == -2) idx = (idx + 3) % 4; // 负数取模后为负数
            else if (command == -1) idx = (idx + 1) % 4;
            else {
                while (command-- > 0) {
                    string pattern = to_string(curX + dirs[idx][0]) + "_" + to_string(curY + dirs[idx][1]);
                    if (!m_obs.count(pattern)) {
                        curX += dirs[idx][0];
                        curY += dirs[idx][1];
                    }
                }
                res = max(res, curX * curX + curY * curY);
            }
        }
        return res;
    }
};
// @lc code=end