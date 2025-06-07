/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
// 1. 记忆化搜索
// 2025-06-04 submission
// 63/63 cases passed
// Runtime: 183 ms, faster than 23.35% of cpp online submissions.
// Memory Usage: 115.7 MB, less than 9.9% of cpp online submissions.
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n)));
        function<int(int, int, int)> dfs;
        dfs = [&](int left, int right, int k) {
            if (left > right) {
                return 0;
            }
            while (left < right && boxes[right] == boxes[right - 1]) {
                --right;
                ++k;
            }
            if (memo[left][right][k] > 0) {
                return memo[left][right][k];
            }
            int ans = dfs(left, right - 1, 0) + (k + 1) * (k + 1);
            for (int h = left; h < right; ++h) {
                if (boxes[h] == boxes[right]) {
                    ans = max(ans, dfs(h + 1, right - 1, 0) + dfs(left, h, k + 1));
                }
            }
            memo[left][right][k] = ans;
            return ans;
        };
        return dfs(0, n - 1, 0);
    }
};
// @lc code=end
