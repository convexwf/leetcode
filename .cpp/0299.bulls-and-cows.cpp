/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
// 1. 哈希表
// 2019-09-27 submission
// 152/152 cases passed
// Runtime: 4 ms, faster than 80.6% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 76.03% of cpp online submissions.
class Solution {
public:
    string getHint(string secret, string guess) {
        int m[256] = {0}, bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            }
            else {
                if (m[secret[i]]++ < 0) ++cows;
                if (m[guess[i]]-- > 0) ++cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
// @lc code=end
