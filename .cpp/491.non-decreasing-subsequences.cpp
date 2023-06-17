/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
// 1. DFS
// 2023-06-16 submission
// 58/58 cases passed
// Runtime: 54 ms, faster than 86.88% of cpp online submissions.
// Memory Usage: 21.9 MB, less than 94.31% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() >= 2) {
            res.push_back(path);
        }
        unordered_set<int> used;
        for (int i = start; i < nums.size(); ++i) {
            if (used.count(nums[i])) {
                continue;
            }
            if (path.empty() || nums[i] >= path.back()) {
                used.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, i + 1, path, res);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2023-06-16 submission
// 58/58 cases passed
// Runtime: 46 ms, faster than 92.82% of cpp online submissions.
// Memory Usage: 24.1 MB, less than 65.35% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res, cur(1);
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int n = cur.size(), start = m[nums[i]];
            m[nums[i]] = n;
            for (int j = start; j < n; ++j) {
                if (!cur[j].empty() && cur[j].back() > nums[i]) continue;
                cur.push_back(cur[j]);
                cur.back().push_back(nums[i]);
                if (cur.back().size() >= 2) res.push_back(cur.back());
            }
        }
        return res;
    }
};
// @lc code=end