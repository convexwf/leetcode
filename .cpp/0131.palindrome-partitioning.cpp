/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
// 1. dfs+回溯
// 2023-02-26 submission
// 32/32 cases passed
// Runtime: 94 ms, faster than 95.92% of cpp online submissions.
// Memory Usage: 49.1 MB, less than 94.86% of cpp online submissions.
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> candidate;
        dfs(res, candidate, s, 0);
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<string>& candidate, string& s, int idx) {
        if (idx == s.length()) {
            res.push_back(candidate);
            return;
        }
        for (int i = idx; i < s.length(); ++i) {
            if (isPalindrome(s, idx, i)) {
                candidate.push_back(s.substr(idx, i - idx + 1));
                dfs(res, candidate, s, i + 1);
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
// 2. dfs+回溯+剪枝
// 2023-02-26 submission
// 32/32 cases passed
// Runtime: 125 ms, faster than 72.79% of cpp online submissions.
// Memory Usage: 53.3 MB, less than 67.03% of cpp online submissions.
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> path;
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || memo[j + 1][i - 1])) {
                    memo[j][i] = true;
                }
            }
        }
        function<void(int)> dfs = [&](int start) {
            if (start == n) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < n; ++i) {
                if (memo[start][i]) {
                    path.push_back(s.substr(start, i - start + 1));
                    dfs(i + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 迭代
// 2023-02-26 submission
// 32/32 cases passed
// Runtime: 264 ms, faster than 21.93% of cpp online submissions.
// Memory Usage: 217.6 MB, less than 5.94% of cpp online submissions.
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
