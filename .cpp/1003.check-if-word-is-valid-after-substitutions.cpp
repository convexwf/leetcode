/*
 * @lc app=leetcode id=1003 lang=cpp
 *
 * [1003] Check If Word Is Valid After Substitutions
 */

// @lc code=start
// 1. 栈
// 2023-09-04 submission
// 96/96 cases passed
// Runtime: 8 ms, faster than 87.34% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 76.13% of cpp online submissions.
class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (char c : s) {
            if (c == 'c') {
                if (stk.size() < 2 || stk[stk.size() - 1] != 'b' || stk[stk.size() - 2] != 'a') {
                    return false;
                }
                stk.pop_back();
                stk.pop_back();
            }
            else {
                stk.push_back(c);
            }
        }
        return stk.empty();
    }
};
// @lc code=end

// @lc code=start
// 2. 字符串修改
// 2023-09-04 submission
// 96/96 cases passed
// Runtime: 12 ms, faster than 63.3% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 91.84% of cpp online submissions.
class Solution {
public:
    bool isValid(string s) {
        int i = 0, n = s.size();
        for (int j = 0; j < n; ++j) {
            s[i++] = s[j];
            if (i >= 3 && s[i - 3] == 'a' && s[i - 2] == 'b' && s[i - 1] == 'c') i -= 3;
        }
        return i == 0;
    }
};
// @lc code=end
