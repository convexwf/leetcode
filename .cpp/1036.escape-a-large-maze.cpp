/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 */

// @lc code=start
// 1. 哈希表+bfs
// 2025-02-07 submission
// 31/31 cases passed
// Runtime: 615 ms, faster than 14.77% of cpp online submissions.
// Memory Usage: 181.9 MB, less than 5.37% of cpp online submissions.
class Solution {
public:
    const long SIZE = 1000000;
    vector<int> dirs = {0, 1, 0, -1, 0};

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long> visited;
        for (const vector<int>& b : blocked) {
            visited.insert(b[0] * SIZE + b[1]);
        }
        return bfs(visited, target, source) && bfs(visited, source, target);
    }

    bool bfs(unordered_set<long> visited, vector<int>& source, vector<int>& target) {
        queue<vector<int>> q;
        q.push(source);
        visited.insert(source[0] * SIZE + source[1]);
        while (!q.empty()) {
            // 200 is the maximum size of the blocked array
            if (visited.size() > 20000 + 200) {
                return true;
            }
            vector<int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = cur[0] + dirs[i];
                int y = cur[1] + dirs[i + 1];
                if (x < 0 || y < 0 || x >= SIZE || y >= SIZE || visited.count(x * SIZE + y)) {
                    continue;
                }
                if (x == target[0] && y == target[1]) {
                    return true;
                }
                visited.insert(x * SIZE + y);
                q.push({x, y});
            }
        }
        return false;
    }
};
// @lc code=end
