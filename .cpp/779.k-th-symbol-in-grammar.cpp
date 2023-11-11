/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
// 1. 二叉树+递归
// 2023-11-06 submission
// 55/55 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 97.68% of cpp online submissions.
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        if (k % 2 == 1) {
            return kthGrammar(n - 1, k / 2 + 1);
        }
        else {
            return 1 - kthGrammar(n - 1, k / 2);
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2023-11-06 submission
// 55/55 cases passed
// Runtime: 2 ms, faster than 51.59% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 97.68% of cpp online submissions.
class Solution {
public:
    int kthGrammar(int n, int k) {
        int res = 0;
        while (n > 1) {
            if (k % 2 == 0) {
                res = !res;
            }
            k = (k + 1) / 2;
            --n;
        }
        return res;
    }
};
// @lc code=end
