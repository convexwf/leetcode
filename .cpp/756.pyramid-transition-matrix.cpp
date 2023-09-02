/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */

// @lc code=start
// 1. 递归回溯
// TLE
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for (string& s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom, mp);
    }

    bool dfs(string& bottom, unordered_map<string, vector<char>>& mp) {
        if (bottom.size() == 1) return true;
        for (int i = 0; i < bottom.size() - 1; ++i) {
            if (mp.count(bottom.substr(i, 2)) == 0) return false;
        }
        vector<string> next;
        getNext(bottom, mp, 0, "", next);
        for (string& s : next) {
            if (dfs(s, mp)) return true;
        }
        return false;
    }

    void getNext(string& bottom, unordered_map<string, vector<char>>& mp, int start, string path,
                 vector<string>& next) {
        if (start == bottom.size() - 1) {
            next.push_back(path);
            return;
        }
        for (char c : mp[bottom.substr(start, 2)]) {
            getNext(bottom, mp, start + 1, path + c, next);
        }
    }
};
// @lc code=end

// @lc code=start
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(7, false)));
        unordered_map<char, unordered_set<string>> m;
        for (string str : allowed) {
            m[str[2]].insert(str.substr(0, 2));
        }
        for (int i = 0; i < n; ++i) {
            dp[n - 1][i][bottom[i] - 'A'] = true;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                for (char ch = 'A'; ch <= 'G'; ++ch) {
                    if (!m.count(ch)) continue;
                    for (string str : m[ch]) {
                        if (dp[i + 1][j][str[0] - 'A'] && dp[i + 1][j + 1][str[1] - 'A']) {
                            dp[i][j][ch - 'A'] = true;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 7; ++i) {
            if (dp[0][0][i]) return true;
        }
        return false;
    }
};
// @lc code=end
