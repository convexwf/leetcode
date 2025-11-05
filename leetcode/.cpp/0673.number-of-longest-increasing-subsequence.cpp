/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
// 1. 动态规划
// 2025-06-09 submission
// 223/223 cases passed
// Runtime: 35 ms, faster than 39.67% of cpp online submissions.
// Memory Usage: 17.7 MB, less than 10.17% of cpp online submissions.
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);    // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
        vector<int> count(n, 1); // count[i] 表示以 nums[i] 结尾的最长递增子序列的个数

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLength = *max_element(dp.begin(), dp.end());
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLength) {
                result += count[i];
            }
        }

        return result;
    }
};
// @lc code=end

// @lc code=start
// 2. 树状数组
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // private:
        //     int lowbit(int x) {
        //         return x & (-x);
        //     }

        //     void update(vector<int>& tree, int index, int delta) {
        //         while (index < tree.size()) {
        //             tree[index] += delta;
        //             index += lowbit(index);
        //         }
        //     }

        //     int query(vector<int>& tree, int index) {
        //         int res = 0;
        //         while (index > 0) {
        //             res += tree[index];
        //             index -= lowbit(index);
        //         }
        //         return res;
        //     }
        // };
