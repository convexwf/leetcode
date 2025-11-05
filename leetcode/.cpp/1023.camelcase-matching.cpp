/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 */

// @lc code=start
// 1. 字符串处理
// 2023-10-19 submission
// 38/38 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.5 MB, less than 51.27% of cpp online submissions.
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (string& query : queries) {
            res.push_back(isMatch(query, pattern));
        }
        return res;
    }

private:
    bool isMatch(const string& query, const string& pattern) {
        int i = 0, j = 0;
        for (char c : query) {
            if (j < pattern.size() && c == pattern[j]) {
                j++;
            }
            else if (c >= 'A' && c <= 'Z') {
                return false;
            }
        }
        return j == pattern.size();
    }
};
// @lc code=end
