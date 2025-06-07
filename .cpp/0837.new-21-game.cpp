/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;      // 初始状态，得分为0的概率为1
        double sum = 1.0; // 用于维护窗口和
        for (int i = 1; i <= n; ++i) {
            dp[i] = sum / maxPts; // 当前得分的概率
            if (i < k) {
                sum += dp[i]; // 更新窗口和
            }
            else {
                sum += dp[i] - (i - maxPts >= 0 ? dp[i - maxPts] : 0); // 移除超出窗口的值
            }
        }
        double result = 0.0;
        for (int i = k; i <= n; ++i) {
            result += dp[i]; // 累加所有不超过n的得分概率
        }
        return result;
    }
};
// @lc code=end
