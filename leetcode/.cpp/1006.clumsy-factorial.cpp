/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 */

// @lc code=start
// 1. 栈
// 2023-11-28 submission
// 84/84 cases passed
// Runtime: 8 ms, faster than 15.3% of cpp online submissions.
// Memory Usage: 6.9 MB, less than 32.01% of cpp online submissions.
class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);
        for (int i = N - 1, j = 0; i > 0; --i, ++j) {
            if (j % 4 == 0) {
                stk.top() *= i;
            }
            else if (j % 4 == 1) {
                stk.top() /= i;
            }
            else if (j % 4 == 2) {
                stk.push(i);
            }
            else {
                stk.push(-i);
            }
        }
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
// @lc code=end

// @lc code=start
// 2. 分组计算
// 2023-11-28 submission
// 84/84 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 35.98% of cpp online submissions.
class Solution {
public:
    int clumsy(int n) {
        if (n <= 2) return n;
        if (n <= 4) return n + 3;
        int res = n * (n - 1) / (n - 2) + (n - 3);
        n -= 4;
        while (n >= 4) {
            res -= n * (n - 1) / (n - 2) - (n - 3);
            n -= 4;
        }
        return res - clumsy(n);
    }
};
// @lc code=end
