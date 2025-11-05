/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
// 1. bfs
// 2024-01-25 submission
// 32/32 cases passed
// Runtime: 9 ms, faster than 67.77% of cpp online submissions.
// Memory Usage: 12.9 MB, less than 39.46% of cpp online submissions.
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                start += to_string(board[i][j]);
            }
        }
        if (start == target) {
            return 0;
        }
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string cur = q.front();
                q.pop();
                for (auto& next : getNexts(cur)) {
                    if (visited.count(next)) {
                        continue;
                    }
                    if (next == target) {
                        return step + 1;
                    }
                    q.push(next);
                    visited.insert(next);
                }
            }
            ++step;
        }
        return -1;
    }

private:
    vector<string> getNexts(string& cur) {
        vector<string> res;
        int index = cur.find('0');
        vector<int> dirs = {-1, 1, -3, 3};
        for (int i = 0; i < dirs.size(); ++i) {
            int nextIndex = index + dirs[i];
            if (nextIndex < 0 || nextIndex >= 6 || (index == 2 && nextIndex == 3) ||
                (index == 3 && nextIndex == 2)) {
                continue;
            }
            swap(cur[index], cur[nextIndex]);
            res.push_back(cur);
            swap(cur[index], cur[nextIndex]);
        }
        return res;
    }
};
// @lc code=end
