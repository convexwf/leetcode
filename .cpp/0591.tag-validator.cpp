/*
 * @lc app=leetcode id=591 lang=cpp
 *
 * [591] Tag Validator
 */

// @lc code=start
// 1. 栈+字符串处理
// 2025-02-24 submission
// 261/261 cases passed
// Runtime: 3 ms, faster than 22.22% of cpp online submissions.
// Memory Usage: 9.4 MB, less than 52.22% of cpp online submissions.
class Solution {
public:
    bool isValid(string code) {
        stack<string> s;
        for (int i = 0; i < code.size(); ++i) {
            if (i > 0 && s.empty()) return false;
            if (code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                i = code.find("]]>", j);
                if (i == string::npos) return false;
                i += 2;
            }
            else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                i = code.find(">", j);
                if (i == string::npos) return false;
                string tag = code.substr(j, i - j);
                if (s.empty() || s.top() != tag) return false;
                s.pop();
            }
            else if (code.substr(i, 1) == "<") {
                int j = i + 1;
                i = code.find(">", j);
                if (i == string::npos) return false;
                string tag = code.substr(j, i - j);
                if (tag.empty() || tag.size() > 9) return false;
                for (char c : tag) {
                    if (!isupper(c)) return false;
                }
                s.push(tag);
            }
        }
        return s.empty();
    }
};
// @lc code=end
