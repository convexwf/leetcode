/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
// 1. 记忆化搜索+二分查找
// 2025-02-07 submission
// 121/121 cases passed
// Runtime: 278 ms, faster than 12.66% of cpp online submissions.
// Memory Usage: 35.7 MB, less than 24.75% of cpp online submissions.
class Solution {
public:
    int superEggDrop(int k, int n) {
        return dfs(k, n);
    }

private:
    unordered_map<int, int> memo;

    int dfs(int k, int n) {
        if (k == 1 || n == 0 || n == 1) {
            return n;
        }
        int key = k * 10000 + n;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int left = 1, right = n;
        int res = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int broken = dfs(k - 1, mid - 1);
            int not_broken = dfs(k, n - mid);
            if (broken > not_broken) {
                right = mid - 1;
                res = min(res, broken + 1);
            }
            else {
                left = mid + 1;
                res = min(res, not_broken + 1);
            }
        }
        memo[key] = res;
        return res;
    }
};
// @lc code=end
