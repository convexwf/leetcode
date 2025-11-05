/*
 * @lc app=leetcode id=159 lang=cpp
 *
 * [159] Longest Substring with At Most Two Distinct Characters
 */

// @lc code=start
// 1. 哈希表+滑动窗口
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n < 3) return n;
        int left = 0, right = 0, max_len = 2;

        char m[128] = {0};
        int count = 0;
        while (right < n) {
            if (m[s[right]] == 0) count++;
            m[s[right]]++;
            while (count > 2) {
                m[s[left]]--;
                if (m[s[left]] == 0) count--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
    }
};
// @lc code=end
