/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
// 1. 贪心算法
// 2024-01-05 submission
// 60/60 cases passed
// Runtime: 2 ms, faster than 63.37% of cpp online submissions.
// Memory Usage: 8.1 MB, less than 83.13% of cpp online submissions.
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> last(time);
        for (auto& clip : clips) {
            if (clip[0] < time) {
                last[clip[0]] = max(last[clip[0]], clip[1]);
            }
        }
        int pre = 0, mx = 0, ans = 0;
        for (int i = 0; i < time; ++i) {
            mx = max(mx, last[i]);
            if (mx == i) {
                return -1;
            }
            if (i == pre) {
                ++ans;
                pre = mx;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2024-01-05 submission
// 60/60 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.1 MB, less than 83.13% of cpp online submissions.
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time + 1, time + 1);
        dp[0] = 0;
        for (int i = 1; i <= time; ++i) {
            for (auto& clip : clips) {
                if (clip[0] <= i && i <= clip[1]) {
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
                }
            }
        }
        return dp[time] == time + 1 ? -1 : dp[time];
    }
};
// @lc code=end
