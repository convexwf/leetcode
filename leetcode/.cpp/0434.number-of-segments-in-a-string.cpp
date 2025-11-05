/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
// 1. 字符串遍历
// 2022-08-26 submission
// 28/28 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.1 MB, less than 55.52% of cpp online submissions.
class Solution {
public:
    int countSegments(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            ++res;
            while (i < n && s[i] != ' ') ++i;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 计数
// 2022-08-26 submission
// 28/28 cases passed
// Runtime: 4 ms, faster than 20.92% of cpp online submissions.
// Memory Usage: 6.1 MB, less than 55.52% of cpp online submissions.
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// C++ 的 getline 函数
// 2022-08-26 submission
// 28/28 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 55.52% of cpp online submissions.
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        istringstream is(s);
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            ++res;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 4. C++ 的 stringstream
// 2024-06-26 submission
// 28/28 cases passed
// Runtime: 2 ms, faster than 47.92% of cpp online submissions.
// Memory Usage: 7.4 MB, less than 5.13% of cpp online submissions.
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string word;
        int res = 0;
        while (ss >> word) {
            res++;
        }
        return res;
    }
};
// @lc code=end
