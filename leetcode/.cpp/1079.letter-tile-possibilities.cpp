/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
// 1. 哈希表+递归
// 2023-10-24 submission
// 86/86 cases passed
// Runtime: 4 ms, faster than 86.07% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 66.13% of cpp online submissions.
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        for (char c : tiles) {
            count[c]++;
        }
        return dfs(count);
    }

    int dfs(unordered_map<char, int>& count) {
        int sum = 0;
        for (auto& p : count) {
            if (p.second == 0) continue;
            sum++;
            p.second--;
            sum += dfs(count);
            p.second++;
        }
        return sum;
    }
};
// @lc code=end
