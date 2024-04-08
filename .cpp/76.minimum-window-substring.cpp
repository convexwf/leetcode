/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
// 2020-07-17 submission
// 267/267 cases passed
// Runtime: 3 ms, faster than 99.69% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 95.59% of cpp online submissions.
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.length() < t.length()) return "";

        int freq[256] = {0};
        for (char c : t) {
            ++freq[c];
        }

        int left = 0, cnt = 0;
        int minLeft = -1, minLen = s.length() + 1;
        for (int pivot = 0; pivot < s.length(); ++pivot) {
            if (--freq[s[pivot]] >= 0) ++cnt;
            while (cnt == t.length()) {
                if (minLen > pivot - left + 1) {
                    minLen = pivot - left + 1;
                    minLeft = left;
                }
                if (++freq[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return minLeft == -1 ? "" : s.substr(minLeft, minLen);
    }
};
// @lc code=end
