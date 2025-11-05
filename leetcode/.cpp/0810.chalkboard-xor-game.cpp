/*
 * @lc app=leetcode id=810 lang=cpp
 *
 * [810] Chalkboard XOR Game
 */

// @lc code=start
// 1. 数学方法
// 2025-06-05 submission
// 168/168 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 16.6 MB, less than 56.28% of cpp online submissions.
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        // If the XOR sum is 0, Alice can always win by mirroring Bob's moves.
        // If the XOR sum is not 0, Alice can still win by making the first move.
        return xorSum == 0 || nums.size() % 2 == 0;
    }
};
// @lc code=end
