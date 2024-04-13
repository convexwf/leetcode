/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
// 2022-07-21 submission
// 26/26 cases passed
// Runtime: 3 ms, faster than 82.05% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 91.79% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out;
        vector<int> visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }

    void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out,
                    vector<vector<int>>& res) {
        if (level == num.size()) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(num[i]);
            permuteDFS(num, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
// @lc code=end
