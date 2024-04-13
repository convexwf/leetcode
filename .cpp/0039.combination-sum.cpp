/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
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
        vector<int> out;
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }

    void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& out,
                           vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 160/160 cases passed
// Runtime: 32 ms, faster than 30.58% of cpp online submissions.
// Memory Usage: 16.7 MB, less than 33.44% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp;
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= target; ++i) {
            vector<vector<int>> cur;
            for (int j = 0; j < candidates.size(); ++j) {
                if (candidates[j] > i) break;
                if (candidates[j] == i) {
                    cur.push_back({candidates[j]});
                    break;
                }
                for (auto a : dp[i - candidates[j] - 1]) {
                    if (candidates[j] > a[0]) continue;
                    a.insert(a.begin(), candidates[j]);
                    cur.push_back(a);
                }
            }
            dp.push_back(cur);
        }
        return dp[target - 1];
    }
};
// @lc code=end
