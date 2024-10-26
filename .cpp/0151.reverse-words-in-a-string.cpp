/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
// 1. 双指针
// 2020-09-19 submission
// 58/58 cases passed
// Runtime: 8 ms, faster than 63.19% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 38.13% of cpp online submissions.
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int i = -1, j = 0;
        for (; j < s.size(); ++j) {
            if (s[j] == ' ') {
                if (j > i + 1) {
                    res = s.substr(i + 1, j - i - 1) + " " + res;
                }
                i = j;
            }
            else if (j == s.size() - 1) {
                res = s.substr(i + 1, j - i) + " " + res;
            }
        }
        return res.substr(0, res.size() - 1);
    }
};
// @lc code=end

// @lc code=start
// 2. 字符串流类 stringstream
// 2023-01-14 submission
// 58/58 cases passed
// Runtime: 14 ms, faster than 37.09% of cpp online submissions.
// Memory Usage: 20.9 MB, less than 17.44% of cpp online submissions.
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string t, res;
        while (ss >> t) {
            res = t + " " + res;
        }
        return res.empty() ? "" : res.substr(0, res.size() - 1);
    }
};
// @lc code=end

// @lc code=start
// 3. stringstream + getline
// 2023-01-14 submission
// 58/58 cases passed
// Runtime: 10 ms, faster than 52.11% of cpp online submissions.
// Memory Usage: 21 MB, less than 17.44% of cpp online submissions.
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        s = "";
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            s = (s.empty() ? t : (t + " " + s));
        }
        return s;
    }
};
// @lc code=end
