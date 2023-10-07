/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

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
