/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */

// @lc code=start
// 1. 贪心算法
// 2023-11-24 submission
// 70/70 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.1 MB, less than 59.9% of cpp online submissions.
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int i = 1, j = n;
        while (i <= j) {
            if (k > 1) {
                ans.push_back(k-- % 2 ? i++ : j--);
            }
            else {
                ans.push_back(i++);
            }
        }
        return ans;
    }
};
// @lc code=end
