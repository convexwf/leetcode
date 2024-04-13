/*
 * @lc app=leetcode id=829 lang=cpp
 *
 * [829] Consecutive Numbers Sum
 */

// @lc code=start
// 1. 数学方法
// 2023-09-05 submission
// 170/170 cases passed
// Runtime: 4 ms, faster than 63.14% of cpp online submissions.
// Memory Usage:  MB, less than 14.57% of cpp online submissions.
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int m = 1; m * (m - 1) / 2 < n; ++m) {
            if ((n - m * (m - 1) / 2) % m == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法（另一种）
// 2023-09-05 submission
// 170/170 cases passed
// Runtime: 4 ms, faster than 63.14% of cpp online submissions.
// Memory Usage:  MB, less than 52.57% of cpp online submissions.
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0, sum = 0;
        for (int i = 1; sum < N; ++i) {
            sum += i;
            if ((N - sum) % i == 0) ++res;
        }
        return res;
    }
};
// @lc code=end
