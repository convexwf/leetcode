/*
 * @lc app=leetcode id=163 lang=cpp
 *
 * [163] Missing Ranges
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int l = lower, r = upper;
        for (int num : nums) {
            if (num < l) continue;
            if (num == l) {
                l++;
                continue;
            }
            res.push_back(l == num - 1 ? to_string(l) : to_string(l) + "->" + to_string(num - 1));
            l = num + 1;
        }
        if (l <= r) res.push_back(l == r ? to_string(l) : to_string(l) + "->" + to_string(r));
        return res;
    }
};
// @lc code=end
