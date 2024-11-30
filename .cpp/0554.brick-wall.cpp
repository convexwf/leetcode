/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

// @lc code=start
// 1. 哈希表
// 2022-11-15 submission
// 87/87 cases passed
// Runtime: 100 ms, faster than 58.84% of cpp online submissions.
// Memory Usage: 21.6 MB, less than 94.68% of cpp online submissions.
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int mx = 0, n = wall.size();
        unordered_map<int, int> m;
        for (auto& row : wall) {
            int sum = 0, cnt = row.size();
            for (int i = 0; i < cnt - 1; ++i) {
                sum += row[i];
                ++m[sum];
                mx = max(mx, m[sum]);
            }
        }
        return n - mx;
    }
};
// @lc code=end
