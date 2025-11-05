/*
 * @lc app=leetcode id=1040 lang=cpp
 *
 * [1040] Moving Stones Until Consecutive II
 */

// @lc code=start
// 1. 贪心算法+双指针
// 2025-03-20 submission
// 27/27 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 16.9 MB, less than 91.46% of cpp online submissions.
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());

        // maximum moves
        int max_moves = max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);

        // minimum moves
        int min_moves = max_moves;
        int i = 0;
        int j = 0;
        while (j < n) {
            while (stones[j] - stones[i] >= n) {
                i++;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2) {
                min_moves = min(min_moves, 2);
            }
            else {
                min_moves = min(min_moves, n - (j - i + 1));
            }
            j++;
        }

        return {min_moves, max_moves};
    }
};
// @lc code=end
