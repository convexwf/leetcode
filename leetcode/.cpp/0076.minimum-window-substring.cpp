/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
// 1. 滑动窗口+哈希表
// 2020-07-17 submission
// 267/267 cases passed
// Runtime: 3 ms, faster than 99.69% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 95.59% of cpp online submissions.
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for (char c : t) {
            freq[c]++;
        }
        int left = 0, right = 0;
        int count = 0;
        int start = 0, len = INT_MAX;
        for (; right < s.size(); right++) {
            if (--freq[s[right]] >= 0) {
                count++;
            }
            while (count == t.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                if (++freq[s[left++]] > 0) {
                    count--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len + 1);
    }
};
// @lc code=end
