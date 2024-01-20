/*
 * @lc app=leetcode id=1276 lang=cpp
 *
 * [1276] Number of Burgers with No Waste of Ingredients
 */

// @lc code=start
// 1. 数学方法-鸡兔同笼
// 2024-01-19 submission
// 1008/1008 cases passed
// Runtime: 3 ms, faster than 67.7% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 55.33% of cpp online submissions.
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x = (tomatoSlices - 2 * cheeseSlices) / 2;
        int y = cheeseSlices - x;
        if (tomatoSlices % 2 == 0 && x >= 0 && y >= 0) {
            return {x, y};
        }
        return {};
    }
};
// @lc code=end
