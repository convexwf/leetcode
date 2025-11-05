/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
// 1. 栈
// 2020-11-20 submission
// 34/34 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.8 MB, less than 20.47% of cpp online submissions.
class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        int num = 0;
        string str;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else if (isalpha(c)) {
                str += c;
            }
            else if (c == '[') {
                numStack.push(num);
                strStack.push(str);
                num = 0;
                str.clear();
            }
            else if (c == ']') {
                int k = numStack.top();
                numStack.pop();
                string t = strStack.top();
                strStack.pop();
                for (int i = 0; i < k; ++i) {
                    t += str;
                }
                str = t;
            }
        }
        return str;
    }
};
// @lc code=end
