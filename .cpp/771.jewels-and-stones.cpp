/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
// 1. 哈希集合
// 2023-08-10 submission
// 255/255 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.3 MB, less than 34.4% of cpp online submissions.
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for (char j : J) {
            jewels.insert(j);
        }
        int ans = 0;
        for (char s : S) {
            if (jewels.count(s)) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
