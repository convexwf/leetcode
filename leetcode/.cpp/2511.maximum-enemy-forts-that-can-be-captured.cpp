/*
 * @lc app=leetcode id=2511 lang=cpp
 *
 * [2511] Maximum Enemy Forts That Can Be Captured
 */

// @lc code=start
// 1. 双指针
// 2024-01-19 submission
// 45/45 cases passed
// Runtime: 4 ms, faster than 44.44% of cpp online submissions.
// Memory Usage: 7.9 MB, less than 90.34% of cpp online submissions.
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0;
        int i = 0, j = 0;
        while (i < n) {
            while (i < n && forts[i] == 0) ++i;
            j = i + 1;
            while (j < n && forts[j] == 0) ++j;
            if (j < n && forts[i] + forts[j] == 0) {
                ans = max(ans, j - i - 1);
            }
            i = j;
        }
        return ans;
    }
};
// @lc code=end
