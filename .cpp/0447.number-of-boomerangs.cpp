/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
// 1. 哈希表+数学方法
// 2023-06-01 submission
// 32/32 cases passed
// Runtime: 591 ms, faster than 61.48% of cpp online submissions.
// Memory Usage: 124.4 MB, less than % of cpp online submissions.
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int res = 0;
        for (auto &p : points) {
            unordered_map<int, int> cnt;
            for (auto &q : points) {
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                ++cnt[dis];
            }
            for (auto &[_, m] : cnt) {
                res += m * (m - 1);
            }
        }
        return res;
    }
};
// @lc code=end
