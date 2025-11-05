/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
// 1. 贪心算法
// 2023-05-17 submission
// 31/31 cases passed
// Runtime: 5 ms, faster than 47.1% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 95.43% of cpp online submissions.
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size(); // 特例
        // 初始化长度为 1，前一步差值为 0
        int ans = 1, pre = 0;
        for (int i = 1; i < nums.size(); i++) {
            // 当前数与上一个数的差值
            int diff = nums[i] - nums[i - 1];
            // 如果当前差值符合摆动的条件
            if ((diff > 0 && pre <= 0) || (diff < 0 && pre >= 0)) {
                // 长度加一 更新前一步差值
                ans++;
                pre = diff;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2023-05-17 submission
// 31/31 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 28.62% of cpp online submissions.
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        vector<int> up(n, 1), down(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};
// @lc code=end
