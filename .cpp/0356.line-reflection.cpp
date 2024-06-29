/*
 * @lc app=leetcode id=356 lang=cpp
 *
 * [356] Line Reflection
 */

// @lc code=start
// 1. 哈希表
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<pair<int, int>, int> hash;
        int minx = INT_MAX, maxx = INT_MIN;
        for (vector<int>& p : points) {
            minx = min(minx, p[0]);
            maxx = max(maxx, p[0]);
            hash[{p[0], p[1]}]++;
        }
        int sum = minx + maxx;
        for (auto& it : hash) {
            int x = it.first.first, y = it.first.second;
            if (hash[{sum - x, y}] != it.second) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
