/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
// 2023-02-28 submission
// 33/33 cases passed
// Runtime: 6 ms, faster than 83.27% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 88.88% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> candidate;
        map<int, int> m;

        int n = nums.size();
        for (int num : nums) {
            ++m[num];
        }
        permute(result, candidate, m, n);
        return result;
    }

    void permute(vector<vector<int>>& result, vector<int>& candidate, map<int, int>& m, int n) {
        if (candidate.size() == n) {
            result.push_back(candidate);
            return;
        }
        for (auto it : m) {
            if (it.second <= 0) continue;
            m[it.first] -= 1;
            candidate.push_back(it.first);
            permute(result, candidate, m, n);
            candidate.pop_back();
            m[it.first] += 1;
        }
    }
};
// @lc code=end
