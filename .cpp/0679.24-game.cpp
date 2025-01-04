/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
// 1. 递归+枚举
// 2025-01-03 submission
// 71/71 cases passed
// Runtime: 11 ms, faster than 65.08% of cpp online submissions.
// Memory Usage: 12.7 MB, less than 69.83% of cpp online submissions.
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr;
        for (int num : nums) {
            arr.push_back(num);
        }
        return dfs(arr);
    }

    bool dfs(vector<double>& arr) {
        if (arr.size() == 1) {
            return fabs(arr[0] - 24) < 1e-6;
        }
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (i == j) {
                    continue;
                }
                vector<double> next;
                for (int k = 0; k < arr.size(); k++) {
                    if (k != i && k != j) {
                        next.push_back(arr[k]);
                    }
                }
                for (int k = 0; k < 4; k++) {
                    if (k < 2 && i > j) {
                        continue;
                    }
                    if (k == 0) {
                        next.push_back(arr[i] + arr[j]);
                    }
                    else if (k == 1) {
                        next.push_back(arr[i] * arr[j]);
                    }
                    else if (k == 2) {
                        next.push_back(arr[i] - arr[j]);
                    }
                    else if (arr[j] != 0) {
                        next.push_back(arr[i] / arr[j]);
                    }
                    else {
                        continue;
                    }
                    if (dfs(next)) {
                        return true;
                    }
                    next.pop_back();
                }
            }
        }
        return false;
    }
};
// @lc code=end
