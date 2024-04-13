/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
// 1. 动态规划
// 2023-05-17 submission
// 15/15 cases passed
// Runtime: 6 ms, faster than 20.64% of cpp online submissions.
// Memory Usage: 7.4 MB, less than 49.5% of cpp online submissions.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法
// 2023-05-17 submission
// 15/15 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 99.62% of cpp online submissions.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int res = 0, cnt = 2, diff = A[1] - A[0];
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == diff) {
                cnt++;
            }
            else {
                if (cnt >= 3) res += (cnt - 1) * (cnt - 2) / 2; // 累加等差子数组个数
                cnt = 2;
                diff = A[i] - A[i - 1];
            }
        }
        if (cnt >= 3) res += (cnt - 1) * (cnt - 2) / 2;
        return res;
    }
};
// @lc code=end
