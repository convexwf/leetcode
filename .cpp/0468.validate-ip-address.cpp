/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

// @lc code=start
// 1. 字符串处理
// 2025-01-02 submission
// 77/77 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 17.08% of cpp online submissions.
class Solution {
public:
    string validIPAddress(string IP) {
        if (isValidIPv4(IP)) {
            return "IPv4";
        }
        if (isValidIPv6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }

    bool isValidIPv4(const string& IP) {
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4) {
            return false;
        }
        for (const string& part : parts) {
            if (part.empty() || part.size() > 3) {
                return false;
            }
            if (part.size() > 1 && part[0] == '0') {
                return false;
            }
            for (char c : part) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            int num = stoi(part);
            if (num < 0 || num > 255) {
                return false;
            }
        }
        return true;
    }

    bool isValidIPv6(const string& IP) {
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) {
            return false;
        }
        for (const string& part : parts) {
            if (part.empty() || part.size() > 4) {
                return false;
            }
            for (char c : part) {
                if (!isxdigit(c)) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> split(const string& s, char delim) {
        vector<string> parts;
        string part;
        istringstream ss(s);
        while (getline(ss, part, delim)) {
            parts.push_back(part);
        }
        // If the last character of the string is the delimiter, add an empty string
        if (!s.empty() && s.back() == delim) {
            parts.push_back("");
        }
        return parts;
    }
};
// @lc code=end
