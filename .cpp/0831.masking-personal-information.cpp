/*
 * @lc app=leetcode id=831 lang=cpp
 *
 * [831] Masking Personal Information
 */

// @lc code=start
// 1. 模拟
// 2023-11-07 submission
// 66/66 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 8.08% of cpp online submissions.
class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            return maskEmail(s);
        }
        else {
            return maskPhone(s);
        }
    }

private:
    string maskEmail(string s) {
        int at = s.find('@');
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string name = s.substr(0, at);
        string domain = s.substr(at + 1);
        return name.substr(0, 1) + "*****" + name.substr(name.size() - 1) + "@" + domain;
    }
    string maskPhone(string s) {
        string digits;
        for (char c : s) {
            if (isdigit(c)) {
                digits += c;
            }
        }
        string local = digits.substr(digits.size() - 10);
        string ans = "***-***-" + local.substr(local.size() - 4);
        if (digits.size() > 10) {
            ans = "+" + string(digits.size() - 10, '*') + "-" + ans;
        }
        return ans;
    }
};
// @lc code=end
