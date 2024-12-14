/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
// 1. 滑动窗口+哈希表
// 2021-03-18 submission
// 64/64 cases passed
// Runtime: 8 ms, faster than 97.04% of cpp online submissions.
// Memory Usage: 8.6 MB, less than 91.9% of cpp online submissions.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> need(256, 0);
        for (char c : p) {
            need[c]++;
        }
        int left = 0, right = 0;
        int valid = 0;
        for (; right < s.size(); ++right) {
            char c = s[right];
            --need[c];
            if (need[c] >= 0) {
                ++valid;
            }
            if (right - left + 1 > p.size()) {
                char d = s[left];
                ++left;
                if (need[d] >= 0) {
                    --valid;
                }
                ++need[d];
            }
            if (valid == p.size()) {
                res.push_back(left);
            }
        }
        return res;
    }
};
// @lc code=end
