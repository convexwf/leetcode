/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
// 1. 贪心算法
// 2024-08-27 submission
// 130/130 cases passed
// Runtime: 9 ms, faster than 77.9% of cpp online submissions.
// Memory Usage:  MB, less than 46.62% of cpp online submissions.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 1;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                ++count;
            }
            else {
                n -= (count - 1) / 2;
                count = 0;
            }
        }
        n -= count / 2;
        return n <= 0;
    }
};
// @lc code=end
