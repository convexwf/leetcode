/*
 * @lc app=leetcode id=370 lang=cpp
 *
 * [370] Range Addition
 */

// @lc code=start
// 1. 差分数组
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for (const vector<int>& update : updates) {
            int start = update[0];
            int end = update[1];
            int inc = update[2];
            ans[start] += inc;
            if (end + 1 < length) {
                ans[end + 1] -= inc;
            }
        }
        for (int i = 1; i < length; ++i) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};
// @lc code=end
