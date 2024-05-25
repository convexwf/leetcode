/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
// 1. 排序+回溯
// 2023-01-14 submission
// 160/160 cases passed
// Runtime: 8 ms, faster than 67.84% of cpp online submissions.
// Memory Usage: 10.8 MB, less than 61% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() <= 0) return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        combinationSumDFS(candidates, target, 0, path, res);
        return res;
    }

    void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& path,
                           vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], i, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end
