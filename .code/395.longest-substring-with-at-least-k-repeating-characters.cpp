/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (44.78%)
 * Likes:    5116
 * Dislikes: 414
 * Total Accepted:    183.6K
 * Total Submissions: 409.9K
 * Testcase Example:  '"aaabb"\n3'
 *
 * Given a string s and an integer k, return the length of the longest
 * substring of s such that the frequency of each character in this substring
 * is greater than or equal to k.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aaabb", k = 3
 * Output: 3
 * Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "ababbc", k = 2
 * Output: 5
 * Explanation: The longest substring is "ababb", as 'a' is repeated 2 times
 * and 'b' is repeated 3 times.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only lowercase English letters.
 * 1 <= k <= 10^5
 *
 *
 */

// @lc code=start
// 2023-02-27 submission
// 37/37 cases passed
// Runtime: 34 ms, faster than 43.46% of C++ online submissions.
// Memory Usage: 6.4 MB, less than 79.14% of C++ online submissions.
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, n = s.size();
        for (int cnt = 1; cnt <= 26; ++cnt) {
            int start = 0, i = 0, uniqueCnt = 0;
            vector<int> charCnt(26);
            while (i < n) {
                bool valid = true;
                if (charCnt[s[i++] - 'a']++ == 0) ++uniqueCnt;
                while (uniqueCnt > cnt) {
                    if (--charCnt[s[start++] - 'a'] == 0) --uniqueCnt;
                }
                for (int j = 0; j < 26; ++j) {
                    if (charCnt[j] > 0 && charCnt[j] < k) valid = false;
                }
                if (valid) res = max(res, i - start);
            }
        }
        return res;
    }
};
// @lc code=end
