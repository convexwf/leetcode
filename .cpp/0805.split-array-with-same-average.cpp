/*
 * @lc app=leetcode id=805 lang=cpp
 *
 * [805] Split Array With Same Average
 */

// @lc code=start
// 1. 二进制枚举
// 2025-06-06 submission
// 111/111 cases passed
// Runtime: 62 ms, faster than 83.43% of cpp online submissions.
// Memory Usage: 20.5 MB, less than 78.49% of cpp online submissions.
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return false;
        }
        int s = accumulate(nums.begin(), nums.end(), 0);
        for (int& v : nums) {
            v = v * n - s;
        }

        int m = n >> 1;
        unordered_set<int> vis;
        for (int i = 1; i < 1 << m; ++i) {
            int t = 0;
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    t += nums[j];
                }
            }
            if (t == 0) {
                return true;
            }
            vis.insert(t);
        }
        for (int i = 1; i < 1 << (n - m); ++i) {
            int t = 0;
            for (int j = 0; j < (n - m); ++j) {
                if (i >> j & 1) {
                    t += nums[m + j];
                }
            }
            if (t == 0 || (i != (1 << (n - m)) - 1 && vis.count(-t))) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
