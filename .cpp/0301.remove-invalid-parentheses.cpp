/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
// 1. bfs
// 2025-02-25 submission
// 129/129 cases passed
// Runtime: 55 ms, faster than 69.76% of cpp online submissions.
// Memory Usage: 20.2 MB, less than 43.97% of cpp online submissions.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> visited;
        bool found = false;
        q.push(s);
        visited.insert(s);
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (isValid(cur)) {
                res.push_back(cur);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] != '(' && cur[i] != ')') continue;
                string next = cur.substr(0, i) + cur.substr(i + 1);
                if (!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        return res;
    }

    bool isValid(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') cnt++;
            if (c == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
};
// @lc code=end

// @lc code=start
// 2025-02-25 submission
// 129/129 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 12.2 MB, less than 63.7% of cpp online submissions.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s, 0, 0, {'(', ')'}, res);
        return res;
    }

    void helper(string s, int last_i, int last_j, vector<char> p, vector<string>& res) {
        int cnt = 0;
        for (int i = last_i; i < s.size(); ++i) {
            if (s[i] == p[0])
                ++cnt;
            else if (s[i] == p[1])
                --cnt;
            if (cnt >= 0) continue;
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == p[1] && (j == last_j || s[j] != s[j - 1])) {
                    helper(s.substr(0, j) + s.substr(j + 1), i, j, p, res);
                }
            }
            return;
        }
        string rev = string(s.rbegin(), s.rend());
        if (p[0] == '(')
            helper(rev, 0, 0, {')', '('}, res);
        else
            res.push_back(rev);
    }
};
// @lc code=end
