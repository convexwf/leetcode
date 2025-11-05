/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
// 1. bfs
// 2023-09-15 submission
// 68/68 cases passed
// Runtime: 7 ms, faster than 76.33% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 17.41% of cpp online submissions.
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int key : rooms[cur]) {
                if (!visited[key]) {
                    q.push(key);
                    visited[key] = true;
                }
            }
        }
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. dfs
// 2023-09-15 submission
// 68/68 cases passed
// Runtime: 7 ms, faster than 76.33% of cpp online submissions.
// Memory Usage:  MB, less than 13.93% of cpp online submissions.
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        dfs(rooms, 0, visited);
        return visited.size() == n;
    }

private:
    void dfs(vector<vector<int>>& rooms, int cur, unordered_set<int>& visited) {
        visited.insert(cur);
        for (int key : rooms[cur]) {
            if (visited.count(key) == 0) {
                dfs(rooms, key, visited);
            }
        }
    }
};
// @lc code=end
