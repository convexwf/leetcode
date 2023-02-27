/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (61.27%)
 * Likes:    7845
 * Dislikes: 239
 * Total Accepted:    498.3K
 * Total Submissions: 813.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 *
 * A palindrome string is a string that reads the same backward as forward.
 *
 *
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 *
 *
 */

// @lc code=start
// 2023-02-26 submission
// 32/32 cases passed
// Runtime: 94 ms, faster than 95.92% of C++ online submissions.
// Memory Usage: 49.1 MB, less than 94.86% of C++ online submissions.
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> candidate;
        helper(res, candidate, s, 0);
        return res;
    }

    void helper(vector<vector<string>>& res, vector<string>& candidate,
                string& s, int idx) {
        if (idx == s.length()) {
            res.push_back(candidate);
            return;
        }
        for (int i = idx; i < s.length(); ++i) {
            if (isPalindrome(s, idx, i)) {
                candidate.push_back(s.substr(idx, i - idx + 1));
                helper(res, candidate, s, i + 1);
                candidate.pop_back();
            }
        }
    }

    bool isPalindrome(string& str, int s, int e) {
        while (s < e) {
            if (str[s++] != str[e--]) return false;
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-26 submission
// 32/32 cases passed
// Runtime: 125 ms, faster than 72.79% of C++ online submissions.
// Memory Usage: 53.3 MB, less than 67.03% of C++ online submissions.
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> out;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }
            }
        }
        helper(s, 0, dp, out, res);
        return res;
    }
    void helper(string s, int start, vector<vector<bool>>& dp, vector<string>& out, vector<vector<string>>& res) {
        if (start == s.size()) { res.push_back(out); return; }
        for (int i = start; i < s.size(); ++i) {
            if (!dp[start][i]) continue;
            out.push_back(s.substr(start, i - start + 1));
            helper(s, i + 1, dp, out, res);
            out.pop_back();
        }
    }
};
// @lc code=end

// @lc code=start
// 2023-02-26 submission
// 32/32 cases passed
// Runtime: 264 ms, faster than 21.93% of C++ online submissions.
// Memory Usage: 217.6 MB, less than 5.94% of C++ online submissions.
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<vector<string>>> res(n + 1);
        res[0].push_back({});
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    string cur = s.substr(j, i - j + 1);
                    for (auto list : res[j]) {
                        list.push_back(cur);
                        res[i + 1].push_back(list);
                    }
                }
            }
        }
        return res[n];
    }
};
// @lc code=end