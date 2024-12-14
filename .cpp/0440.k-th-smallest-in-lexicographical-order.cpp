/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
// 1. 十叉树先序遍历
// 2024-12-12 submission
// 69/69 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 10.31% of cpp online submissions.
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            int steps = calSteps(n, cur, cur + 1);
            if (steps <= k) {
                cur += 1;
                k -= steps;
            }
            else {
                cur *= 10;
                --k;
            }
        }
        return cur;
    }

private:
    int calSteps(int n, long long n1, long long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min(n + 1LL, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};
// @lc code=end
