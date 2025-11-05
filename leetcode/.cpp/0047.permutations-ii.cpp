/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
// 1. 哈希表+dfs+回溯
// 2023-02-28 submission
// 33/33 cases passed
// Runtime: 6 ms, faster than 83.27% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 88.88% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        unordered_map<int, int> hash;
        for (int& num : nums) {
            hash[num]++;
        }
        dfs(res, path, hash, nums.size());
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, unordered_map<int, int>& hash, int n) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        for (auto& [num, count] : hash) {
            if (count > 0) {
                path.push_back(num);
                hash[num]--;
                dfs(res, path, hash, n);
                path.pop_back();
                hash[num]++;
            }
        }
    }
};
// @lc code=end
