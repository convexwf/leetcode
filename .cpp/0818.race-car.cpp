/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 */

// @lc code=start
// 1. bfs+哈希表
// 2023-12-12 submission
// 55/55 cases passed
// Runtime: 492 ms, faster than 30.53% of cpp online submissions.
// Memory Usage: 83.4 MB, less than 29.65% of cpp online submissions.
class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        unordered_set<string> visited;
        q.push({0, 1});
        visited.insert("0,1");
        int res = 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                auto [pos, speed] = q.front();
                q.pop();
                if (pos == target) return res;
                string state = to_string(pos) + "," + to_string(speed);
                // accelerate
                int nextPos = pos + speed, nextSpeed = speed * 2;
                string nextState = to_string(nextPos) + "," + to_string(nextSpeed);
                if (nextPos > 0 && nextPos < 2 * target && !visited.count(nextState)) {
                    q.push({nextPos, nextSpeed});
                    visited.insert(nextState);
                }
                // reverse
                nextPos = pos;
                nextSpeed = speed > 0 ? -1 : 1;
                nextState = to_string(nextPos) + "," + to_string(nextSpeed);
                if (nextPos > 0 && nextPos < 2 * target && !visited.count(nextState)) {
                    q.push({nextPos, nextSpeed});
                    visited.insert(nextState);
                }
            }
            ++res;
        }
        return -1;
    }
};
// @lc code=end
