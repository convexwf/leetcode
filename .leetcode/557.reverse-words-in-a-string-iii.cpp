/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (76.02%)
 * Likes:    2160
 * Dislikes: 139
 * Total Accepted:    352.1K
 * Total Submissions: 460.7K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string s, reverse the order of characters in each word within a
 * sentence while still preserving whitespace and initial word order.
 * 
 * 
 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Example 2:
 * Input: s = "God Ding"
 * Output: "doG gniD"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s contains printable ASCII characters.
 * s does not contain any leading or trailing spaces.
 * There is at least one word in s.
 * All the words in s are separated by a single space.
 * 
 * 
 */

// @lc solution=start
解题思路

1. 栈：遇到字符就压入栈，遇到空格就出栈
2. 双指针法：O(1) 空间复杂度。
// @lc solution=end

// @lc code=start
// 2021-12-23 submission
// 29/29 cases passed
// Runtime: 20 ms, faster than 31.6% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 33.39% of C++ online submissions.
class Solution {
public:
    string reverseWords(string s) {
        stack<char> stk;
        string res;
        for (char c : s) {
            if (c == ' ') {
                while (!stk.empty()) {
                    res.append(1, stk.top());
                    stk.pop();
                }
                res.append(1, ' ');
            }
            else stk.push(c);
        }
        while (!stk.empty()) {
            res.append(1, stk.top());
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2021-12-23 submission
// 29/29 cases passed
// Runtime: 24 ms, faster than 20.99% of C++ online submissions.
// Memory Usage: 11 MB, less than 31.29% of C++ online submissions.
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(), idx = 0;
        int l = 0, r = 0;
        while (idx < n && s[++idx] != ' ') {
            r = idx - 1;
            while (l < r) {
                char c = s[l];
                s[l] = s[r];
                s[r] = c;
            }
            l = ++idx;
        }
        return s;
    }
};
// @lc code=end