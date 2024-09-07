/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
// 1. 排序+贪心算法
// 2023-02-27 submission
// 205/205 cases passed
// Runtime: 75 ms, faster than 71.64% of cpp online submissions.
// Memory Usage: 24.5 MB, less than 34.17% of cpp online submissions.
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0, end = INT_MIN;
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        for (auto pair : pairs) {
            if (pair[0] > end) {
                ++res;
                end = pair[1];
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 排序+动态规划
// 2024-09-02 submission
// 206/206 cases passed
// Runtime: 86 ms, faster than 46.21% of cpp online submissions.
// Memory Usage: 26.8 MB, less than 58.28% of cpp online submissions.
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
