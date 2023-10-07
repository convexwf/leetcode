/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
// 2023-01-14 submission
// 3999/3999 cases passed
// Runtime: 15 ms, faster than 61.68% of C++ online submissions.
// Memory Usage: 7.8 MB, less than 49.86% of C++ online submissions.
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); ++i) {
            int val = m[s[i]];
            if (i == s.size() - 1 || m[s[i+1]] <= m[s[i]]) res += val;
            else res -= val;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 3999/3999 cases passed
// Runtime: 24 ms, faster than 33.74% of C++ online submissions.
// Memory Usage: 7.8 MB, less than 44.47% of C++ online submissions.
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || m[s[i]] <= m[s[i - 1]]) res += m[s[i]];
            else res += m[s[i]] - 2 * m[s[i - 1]];
        }
        return res;
    }
};
// @lc code=end