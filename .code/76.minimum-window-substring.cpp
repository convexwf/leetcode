/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (39.49%)
 * Likes:    11305
 * Dislikes: 549
 * Total Accepted:    806.1K
 * Total Submissions: 2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 */

// @lc code=start
// 2020-07-17 submission
// 267/267 cases passed
// Runtime: 3 ms, faster than 99.69% of C++ online submissions.
// Memory Usage: 7.8 MB, less than 95.59% of C++ online submissions.
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.length() < t.length()) return "";

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
