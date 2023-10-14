/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
// 1. 滑动窗口
// 2023-10-12 submission
// 41/41 cases passed
// Runtime: 7 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 30.35% of cpp online submissions.
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxCount = 0;
        vector<int> count(26, 0);
        while (right < s.size()) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);
            if (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};
// @lc code=end
