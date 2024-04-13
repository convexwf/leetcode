/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
// 1. 动态规划
// 2023-06-28 submission
// 126/126 cases passed
// Runtime: 20 ms, faster than 50.33% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 47.09% of cpp online submissions.
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = i - 1; j > 1; --j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + i / j;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2023-06-28 submission
// 126/126 cases passed
// Runtime: 4 ms, faster than 67.46% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 97.42% of cpp online submissions.
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; ++i) {
            if (n % i == 0) return i + minSteps(n / i);
        }
        return n;
    }
};
// @lc code=end

// @lc code=start
// 3. 数学方法-质因数分解
// 2023-06-28 submission
// 126/126 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 75.93% of cpp online submissions.
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        return ans;
    }
};
// @lc code=end
