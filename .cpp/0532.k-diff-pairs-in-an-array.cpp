/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
// 2022-11-15 submission
// 60/60 cases passed
// Runtime: 15 ms, faster than 96.37% of cpp online submissions.
// Memory Usage: 13.2 MB, less than 74.4% of cpp online submissions.
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        unordered_map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto a : m) {
            if (k == 0 && a.second > 1) ++res;
            if (k > 0 && m.count(a.first + k)) ++res;
        }
        return res;
    }
};
// @lc code=end
