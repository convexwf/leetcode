/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (49.08%)
 * Likes:    9559
 * Dislikes: 295
 * Total Accepted:    665.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 *
 *
 */

// @lc code=start
// 2021-03-18 submission
// 64/64 cases passed
// Runtime: 8 ms, faster than 97.04% of C++ online submissions.
// Memory Usage: 8.6 MB, less than 91.9% of C++ online submissions.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m[256] = {0};   // 数据类型不能用char！！！
        int len = p.length();
        for (char c : p) {
            ++m[c];
        }

        int l = -1;
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            --m[s[i]];
            while (m[s[i]] < 0) ++m[s[++l]];
            if (i - l == len) res.push_back(l + 1);
        }
        return res;
    }
};
// @lc code=end
