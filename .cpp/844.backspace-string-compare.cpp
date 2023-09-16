/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
// 1. 栈模拟
// 2023-09-15 submission
// 114/114 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.9 MB, less than 9.36% of cpp online submissions.
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(string s) {
        string ret;
        for (char c : s) {
            if (c != '#') {
                ret.push_back(c);
            }
            else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }
};
// @lc code=end

// @lc code=start
// 2. 倒序遍历
// 2023-09-15 submission
// 114/114 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 9.36% of cpp online submissions.
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skip_s = 0, skip_t = 0;
        while (i >= 0 || j >= 0) {
            // 去除退格符
            while (i >= 0) {
                if (s[i] == '#') {
                    skip_s++;
                    i--;
                }
                else if (skip_s > 0) {
                    skip_s--;
                    i--;
                }
                else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    skip_t++;
                    j--;
                }
                else if (skip_t > 0) {
                    skip_t--;
                    j--;
                }
                else {
                    break;
                }
            }
            // 如果两个字符串都没有遍历结束
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            // 如果只有一个字符串遍历结束
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};
// @lc code=end
