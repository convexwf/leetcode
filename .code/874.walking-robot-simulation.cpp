/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
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