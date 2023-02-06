/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (38.56%)
 * Likes:    6078
 * Dislikes: 195
 * Total Accepted:    342.3K
 * Total Submissions: 887.7K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * You are given an integer array prices where prices[i] is the price of a
 * given stock on the i^th day, and an integer k.
 *
 * Find the maximum profit you can achieve. You may complete at most k
 * transactions.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
 * profit = 3-0 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= 100
 * 1 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 *
 *
 */

// @lc code=start
// 2020-07-24 submission
// 210/210 cases passed
// Runtime: 9 ms, faster than 90.33% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 84.39% of C++ online submissions.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k > prices.size()) return maxProfit_largetrades(prices);
        vector<int> local(k+1, 0), global(k+1, 0);
        for (int day = 1; day < prices.size(); day++) {
            int diff = prices[day] - prices[day-1];
            for (int j = k; j >= 1; j--) { // 为什么要 j 从 k 遍历到 1，而不是 1 遍历到 k
                local[j] = max(global[j-1]+max(diff, 0), local[j]+diff);
                global[j] = max(local[j], global[j]);
                // cout << "day:" << day << " j:" << j << " local:"<<local[j] << " global:" << global[j] << endl;
            }
        }
        return global[k];
    }

    int maxProfit_largetrades(vector<int>& prices) {
        int maxValue = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1])
                maxValue += (prices[i]-prices[i-1]);
        }
        return maxValue;
    }
};
// @lc code=end
