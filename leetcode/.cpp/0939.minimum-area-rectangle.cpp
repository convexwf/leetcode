/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */

// @lc code=start
// 1. 有序集合+哈希表+排序
// 2023-11-30 submission
// 137/137 cases passed
// Runtime: 464 ms, faster than 32.61% of cpp online submissions.
// Memory Usage: 126.3 MB, less than 16.85% of cpp online submissions.
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> x2y;
        for (auto& p : points) {
            x2y[p[0]].push_back(p[1]);
        }
        int ans = INT_MAX;
        unordered_map<int, int> lastx;
        for (auto& [x, ylist] : x2y) {
            sort(ylist.begin(), ylist.end());
            for (int i = 0; i < ylist.size(); ++i) {
                for (int j = i + 1; j < ylist.size(); ++j) {
                    int y1 = ylist[i], y2 = ylist[j];
                    int key = y1 * 40001 + y2;
                    if (lastx.count(key)) {
                        ans = min(ans, (x - lastx[key]) * (y2 - y1));
                    }
                    lastx[key] = x;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
