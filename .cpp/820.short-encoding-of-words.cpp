/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
// 2023-02-27 submission
// 38/38 cases passed
// Runtime: 36 ms, faster than 95.54% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 97.03% of cpp online submissions.
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0, n = words.size();
        for (int i = 0; i < n; ++i) reverse(words[i].begin(), words[i].end());
        sort(words.begin(), words.end());
        for (int i = 0; i < n - 1; ++i) {
            res += (words[i] == words[i + 1].substr(0, words[i].size())) ? 0 : words[i].size() + 1;
        }
        return res + words.back().size() + 1;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-27 submission
// 38/38 cases passed
// Runtime: 36 ms, faster than 95.54% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 97.03% of cpp online submissions.
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0, n = words.size();
        for (int i = 0; i < n; ++i) reverse(words[i].begin(), words[i].end());
        sort(words.begin(), words.end());
        for (int i = 0; i < n - 1; ++i) {
            res += (words[i] == words[i + 1].substr(0, words[i].size())) ? 0 : words[i].size() + 1;
        }
        return res + words.back().size() + 1;
    }
};
// @lc code=end
