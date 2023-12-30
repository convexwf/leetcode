/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
// 1. DFS
// 2023-12-25 submission
// 63/63 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 9.9 MB, less than 89.55% of cpp online submissions.
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        dfs(s, 0, res);
        return res;
    }

private:
    void dfs(string& s, int i, vector<string>& res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        dfs(s, i + 1, res);
        if (isalpha(s[i])) {
            s[i] ^= 32;
            dfs(s, i + 1, res);
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作
// 2023-12-25 submission
// 63/63 cases passed
// Runtime: 10 ms, faster than 19.72% of cpp online submissions.
// Memory Usage: 9.7 MB, less than 95.52% of cpp online submissions.
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        int cnt = 0;
        for (char c : s) {
            if (isalpha(c)) {
                ++cnt;
            }
        }
        vector<string> ans;
        for (int i = 0; i < (1 << cnt); ++i) {
            int j = 0;
            string cur;
            for (char c : s) {
                if (isalpha(c)) {
                    if ((i >> j) & 1) {
                        cur += toupper(c);
                    }
                    else {
                        cur += tolower(c);
                    }
                    ++j;
                }
                else {
                    cur += c;
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
// @lc code=end
