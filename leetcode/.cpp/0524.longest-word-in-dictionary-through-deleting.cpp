/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
// 1. 自定义排序+双指针
// 2023-09-12 submission
// 31/31 cases passed
// Runtime: 44 ms, faster than 84.06% of cpp online submissions.
// Memory Usage: 14.9 MB, less than 80.17% of cpp online submissions.
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a < b;
            }
            return a.size() > b.size();
        });
        for (const string& str : dictionary) {
            if (isSubsequence(str, s)) {
                return str;
            }
        }
        return "";
    }

    bool isSubsequence(const string& str, const string& s) {
        int i = 0, j = 0;
        while (i < str.size() && j < s.size()) {
            if (str[i] == s[j]) {
                ++i;
            }
            ++j;
        }
        return i == str.size();
    }
};
// @lc code=end

// @lc code=start
// 2. 直接遍历+双指针
// 2023-09-12 submission
// 31/31 cases passed
// Runtime: 45 ms, faster than 81.82% of cpp online submissions.
// Memory Usage: 14.9 MB, less than 80.17% of cpp online submissions.
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (const string& str : dictionary) {
            int i = 0;
            for (char c : s) {
                if (i < str.size() && c == str[i]) ++i;
            }
            if (i == str.size() && str.size() >= res.size()) {
                if (str.size() > res.size() || str < res) {
                    res = str;
                }
            }
        }
        return res;
    }
};
// @lc code=end
