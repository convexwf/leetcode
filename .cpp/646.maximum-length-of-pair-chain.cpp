/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
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
