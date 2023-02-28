/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (66.75%)
 * Likes:    8667
 * Dislikes: 188
 * Total Accepted:    551K
 * Total Submissions: 825.5K
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of palindromic substrings in it.
 *
 * A string is a palindrome when it reads the same backward as forward.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
// 2023-02-28 submission
// 130/130 cases passed
// Runtime: 17 ms, faster than 51.18% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 56.95% of C++ online submissions.
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        vector<vector<bool>> judge(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (j + 2 > i || judge[j + 1][i - 1])) {
                    judge[j][i] = true;
                    ++res;
                }
            }
        }
        return res;
    }
};
// @lc code=end