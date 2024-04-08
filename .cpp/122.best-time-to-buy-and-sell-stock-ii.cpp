/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
// 1. 贪心算法
// 2022-07-28 submission
// 200/200 cases passed
// Runtime: 17 ms, faster than 23.37% of cpp online submissions.
// Memory Usage: 13.1 MB, less than 55.26% of cpp online submissions.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxValue = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) maxValue += (prices[i] - prices[i - 1]);
        }
        return maxValue;
    }
};
// @lc code=end
