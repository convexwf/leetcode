/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */

// @lc code=start
// 1. 记忆化搜索
// 2024-02-05 submission
// 62/62 cases passed
// Runtime: 375 ms, faster than 65.04% of cpp online submissions.
// Memory Usage: 69.9 MB, less than 5.59% of cpp online submissions.
class Solution {
private:
    unordered_map<string, bool> memo;

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, string> rules;
        for (string str : allowed) {
            rules[str.substr(0, 2)].append(1, str[2]);
        }
        return dfs(bottom, "", rules);
    }
    bool dfs(const string& cur, string above, unordered_map<string, string>& rules) {
        if (cur.size() == 1) return true;
        if (above.size() + 1 == cur.size()) return dfs(above, "", rules);
        string pattern = cur + "." + above;
        if (memo.count(pattern)) {
            return memo[pattern];
        }
        string base = cur.substr(above.size(), 2);
        if (rules.count(base)) {
            for (char& ch : rules[base]) {
                if (dfs(cur, above + string(1, ch), rules)) {
                    return memo[pattern] = true;
                }
            }
        }
        return memo[pattern] = false;
    }
};
// @lc code=end
