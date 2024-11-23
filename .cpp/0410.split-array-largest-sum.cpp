/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
// 1. 二分查找
// 2023-05-20 submission
// 31/31 cases passed
// Runtime: 5 ms, faster than 43.06% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 82.02% of cpp online submissions.
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = 0; // 数组和有可能超过 INT_MAX
        for (int num : nums) {
            left = max(left, (long)num); // 左边界为最大值
            right += num;                // 右边界为所有元素之和
        }
        while (left <= right) {
            long mid = left + (right - left) / 2;
            int cnt = 1;  // 子数组数量
            long sum = 0; // 当前子数组的和
            for (int num : nums) {
                if (sum + num > mid) { // 分割出新的子数组
                    cnt++;
                    sum = num;
                }
                else {
                    sum += num;
                }
            }
            if (cnt > m) { // 子数组数量过多，说明mid偏小，需要调整左边界
                left = mid + 1;
            }
            else { // 子数组数量不足，说明mid偏大，需要调整右边界
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找+前缀和数组
// 2023-05-20 submission
// 31/31 cases passed
// Runtime: 6 ms, faster than 38.81% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 82.02% of cpp online submissions.
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = 0;                // 数组和有可能超过 INT_MAX
        vector<long> prefixSum(nums.size() + 1); // 前缀和数组
        for (int i = 1; i <= nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
            left = max(left, (long)nums[i - 1]); // 左边界为最大值
            right += nums[i - 1];                // 右边界为所有元素之和
        }
        while (left <= right) {                   // 注意循环条件
            long mid = left + (right - left) / 2; // 中间值
            int cnt = 0;                          // 子数组数量，初始值为0
            for (int i = 1, j = 0; i <= nums.size(); i++) {
                if (prefixSum[i] - prefixSum[j] > mid) { // 分割出新的子数组
                    cnt++;
                    j = i - 1;
                }
            }
            cnt++;         // 最后一个子数组
            if (cnt > m) { // 子数组数量过多，说明mid偏小，需要调整左边界
                left = mid + 1;
            }
            else { // 子数组数量不足，说明mid偏大，需要调整右边界
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

// @lc code=start
// 3. 动态规划
// 2023-05-20 submission
// 31/31 cases passed
// Runtime: 1462 ms, faster than 5.04% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 6.19% of cpp online submissions.
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INT_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end
