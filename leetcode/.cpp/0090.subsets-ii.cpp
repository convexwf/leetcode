/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
// 1. 排序+dfs
// 2024-07-03 submission
// 20/20 cases passed
// Runtime: 4 ms, faster than 49.08% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 99.84% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, path, res);
        return res;
    }

    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, res);
            path.pop_back();
        }
    }
};

// 添加顺序为
// []
// [1]
// [1 2]
// [1 2 2]
// [2]
// [2 2]
// @lc code=end

// @lc code=start
// 2. 排序+二进制枚举
// 2024-07-03 submission
// 20/20 cases passed
// Runtime: 6 ms, faster than 21.76% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 57.47% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (i > 0 && (mask & (1 << (i - 1))) == 0 && nums[i] == nums[i - 1]) {
                        flag = false;
                        break;
                    }
                    subset.push_back(nums[i]);
                }
            }
            if (flag) {
                res.push_back(subset);
            }
        }
        return res;
    }
};

// 添加顺序为
// []
// [1]
// [2]
// [1 2]
// [2 2]
// [1 2 2]
// @lc code=end

// @lc code=start
// 3. 嵌套生成
// 2023-01-14 submission
// 20/20 cases passed
// Runtime: 6 ms, faster than 51.11% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 95.58% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& S) {
        if (S.empty()) return {};
        vector<vector<int>> res;
        vector<int> out;
        sort(S.begin(), S.end());
        getSubsets(S, 0, out, res);
        return res;
    }
    void getSubsets(vector<int>& S, int pos, vector<int>& out, vector<vector<int>>& res) {
        res.push_back(out);
        for (int i = pos; i < S.size(); ++i) {
            out.push_back(S[i]);
            getSubsets(S, i + 1, out, res);
            out.pop_back();
            while (i + 1 < S.size() && S[i] == S[i + 1]) ++i;
        }
    }
};

// 添加顺序为
// []
// [1]
// [1 2]
// [1 2 2]
// [2]
// [2 2]
// @lc code=end
