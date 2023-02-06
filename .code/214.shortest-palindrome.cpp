/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (32.25%)
 * Likes:    3006
 * Dislikes: 211
 * Total Accepted:    151.3K
 * Total Submissions: 469.2K
 * Testcase Example:  '"aacecaaa"'
 *
 * You are given a string s. You can convert s to a palindrome by adding
 * characters in front of it.
 * 
 * Return the shortest palindrome you can find by performing this
 * transformation.
 * 
 * 
 * Example 1:
 * Input: s = "aacecaaa"
 * Output: "aaacecaaa"
 * Example 2:
 * Input: s = "abcd"
 * Output: "dcbabcd"
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of lowercase English letters only.
 * 
 * 
 */

// @lc code=start
// 2023-02-06 submission
// 121/121 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7.9 MB, less than 50% of C++ online submissions.
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> next(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = next[i - 1];
            while (j > 0 && t[i] != t[j]) j = next[j - 1];
            next[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - next.back()) + s;
    }
};
// @lc code=end