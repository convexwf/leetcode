/*
 * @lc app=leetcode id=573 lang=cpp
 *
 * [573] Squirrel Simulation
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel,
                    vector<vector<int>>& nuts) {
        int res = 0, maxDiff = INT_MIN;
        for (auto& nut : nuts) {
            int dist = abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]);
            res += 2 * dist;
            maxDiff = max(maxDiff, dist - abs(nut[0] - squirrel[0]) - abs(nut[1] - squirrel[1]);
        }
        return res - maxDiff;
    }
};
// @lc code=end
