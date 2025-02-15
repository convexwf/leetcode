/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
// 1. 记忆化搜索+二分查找
// 2023-03-12 submission
// 52/52 cases passed
// Runtime: 161 ms, faster than 67.85% of cpp online submissions.
// Memory Usage: 24.8 MB, less than 79.23% of cpp online submissions.
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        function<int(int)> checkPos = [&](int pos) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (stones[mid] == pos) {
                    return mid;
                }
                else if (stones[mid] < pos) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            return -1;
        };

        unordered_map<int, unordered_map<int, bool>> memo;
        function<bool(int, int)> dfs = [&](int pos, int k) {
            if (pos == stones[n - 1]) {
                return true;
            }
            if (memo.count(pos) && memo[pos].count(k)) {
                return memo[pos][k];
            }
            for (int i = k - 1; i <= k + 1; ++i) {
                if (i > 0) {
                    int nextPos = pos + i;
                    int nextIndex = checkPos(nextPos);
                    if (nextIndex != -1 && dfs(stones[nextIndex], i)) {
                        memo[pos][k] = true;
                        return true;
                    }
                }
            }
            return memo[pos][k] = false;
        };
        return dfs(stones[0], 0);
    }
};
// @lc code=end
