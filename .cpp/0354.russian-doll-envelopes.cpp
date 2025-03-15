/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
// 1. 排序+贪心算法+二分查找
// 2023-05-12 submission
// 87/87 cases passed
// Runtime: 388 ms, faster than 67.67% of cpp online submissions.
// Memory Usage: 77.5 MB, less than 90.91% of cpp online submissions.
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> dp;
        for (const vector<int>& envelope : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
            if (it == dp.end()) {
                dp.push_back(envelope[1]);
            }
            else {
                *it = envelope[1];
            }
        }
        return dp.size();
    }
};
// @lc code=end
