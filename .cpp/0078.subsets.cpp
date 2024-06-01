/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
// 1. DFS回溯
// 2022-07-26 submission
// 10/10 cases passed
// Runtime: 6 ms, faster than 39.17% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 70.41% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, path, res);
        for (auto& vec : res) {
            cout << "[";
            for (auto& num : vec) {
                cout << num << ",";
            }
            cout << "], ";
        }
        return res;
    }

    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作+枚举
// 2022-07-26 submission
// 10/10 cases passed
// Runtime: 5 ms, faster than 43.24% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 70.41% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int count = 1 << nums.size();
        for (int i = 0; i < count; i++) {
            vector<int> vec;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) vec.push_back(nums[j]);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 非递归遍历
// 2022-07-26 submission
// 10/10 cases passed
// Runtime: 7 ms, faster than 34.37% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 70.41% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        for (int i = 0; i < nums.size(); ++i) {
            int n = res.size();
            for (int j = 0; j < n; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
