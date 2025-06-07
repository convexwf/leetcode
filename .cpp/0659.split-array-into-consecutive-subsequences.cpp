/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
// 1. 哈希表+贪心算法
// 2025-06-05 submission
// 187/187 cases passed
// Runtime: 16 ms, faster than 64.82% of cpp online submissions.
// Memory Usage: 62.1 MB, less than 74.7% of cpp online submissions.
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, tails;
        for (int num : nums) {
            count[num]++;
        }

        for (int num : nums) {
            if (count[num] == 0) continue;

            if (tails[num] > 0) {
                tails[num]--;
                tails[num + 1]++;
            }
            else if (count[num + 1] > 0 && count[num + 2] > 0) {
                count[num + 1]--;
                count[num + 2]--;
                tails[num + 3]++;
            }
            else {
                return false;
            }
            count[num]--;
        }

        return true;
    }
};
// @lc code=end
