/*
 * @lc app=leetcode id=755 lang=cpp
 *
 * [755] Pour Water
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        while (volume--) {
            int best = k;
            for (int d = -1; d <= 1; d += 2) {
                int i = k + d;
                while (i >= 0 && i < heights.size() && heights[i] <= heights[i - d]) {
                    if (heights[i] < heights[best]) {
                        best = i;
                    }
                    if (heights[i] < heights[i - d]) {
                        break;
                    }
                    i += d;
                }
                if (best != k) {
                    break;
                }
            }
            ++heights[best];
        }
        return heights;
    }
};
// @lc code=end
