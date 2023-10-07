/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
// 2022-07-26 submission
// 10/10 cases passed
// Runtime: 7 ms, faster than 34.37% of C++ online submissions.
// Memory Usage: 7.1 MB, less than 70.41% of C++ online submissions.
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

// @lc code=start
// 2022-07-26 submission
// 10/10 cases passed
// Runtime: 6 ms, faster than 39.17% of C++ online submissions.
// Memory Usage: 7.1 MB, less than 70.41% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        DFS(nums, temp, result, 0);
        return result;
    }

    void DFS(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& result, int pivot) {
        result.push_back(curr);
        for(int i = pivot; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            DFS(candidates, curr, result, i+1);
            curr.pop_back();
        }
    }
};
// @lc code=end

// @lc code=start
// 2022-07-26 submission
// 10/10 cases passed
// Runtime: 5 ms, faster than 43.24% of C++ online submissions.
// Memory Usage: 7.2 MB, less than 70.41% of C++ online submissions.
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
