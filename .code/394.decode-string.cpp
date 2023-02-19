/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (57.95%)
 * Likes:    10309
 * Dislikes: 460
 * Total Accepted:    615.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 *
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 *
 *
 */

// @lc code=start
// 2020-11-20 submission
// 34/34 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.8 MB, less than 20.47% of C++ online submissions.
class Solution {
public:
    string decodeString(string s) {
        s = "1[" + s + "]";
        int len = s.length(), cur = 0;
        stack<int> nums;
        stack<string> stk;
        while(cur < len) {
            if (isdigit(s[cur])) {
                int tail = cur;
                while(isdigit(s[++tail]));
                nums.push(stoi(s.substr(cur, tail - cur)));
                cur = tail;
            }
            else if (s[cur] == ']') {
                string tmp = "", res = "";
                while (stk.top() != "[") {
                    tmp.insert(0, stk.top());
                    stk.pop();
                }
                for (int i = 0; i < nums.top(); i++)
                    res += tmp;
                nums.pop(); stk.pop();
                stk.push(res);
                cur++; // 不能够在判断语句 s[cur++] == ']'，这样即使不满足条件也会 cur++
            }
            else stk.push(string(1, s[cur++]));
        }
        return stk.top();
    }
};
// @lc code=end
