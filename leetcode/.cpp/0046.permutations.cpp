/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
// 1. dfs+回溯
// 2022-07-21 submission
// 26/26 cases passed
// Runtime: 3 ms, faster than 82.05% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 91.79% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(num.size(), false);
        dfs(res, path, num, visited);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& num, vector<bool>& visited) {
        if (path.size() == num.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            path.push_back(num[i]);
            dfs(res, path, num, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end
