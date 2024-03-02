/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
// 1. 维护前缀最小值
// 2022-07-28 submission
// 211/211 cases passed
// Runtime: 238 ms, faster than 25.62% of C++ online submissions.
// Memory Usage: 93.3 MB, less than 52.3% of C++ online submissions.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minPrice = prices[0];
        int maxPro = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxPro = max(maxPro, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxPro;
    }
};
// @lc code=end
