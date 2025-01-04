/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
// 1. dfs
// 2022-11-14 submission
// 145/145 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 41.34% of cpp online submissions.
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> candidates;
        dfs(s, 0, candidates, res);
        return res;
    }

    void dfs(const string& s, int idx, vector<string>& candidates, vector<string>& res) {
        if (candidates.size() == 4) {
            if (idx == s.size()) {
                res.push_back(candidates[0] + '.' + candidates[1] + '.' + candidates[2] + '.' +
                              candidates[3]);
            }
            return;
        }

        for (int i = 1; i <= 3; ++i) {
            if (idx + i > s.size()) {
                break;
            }
            string num = s.substr(idx, i);
            if ((num.size() > 1 && num[0] == '0') || stoi(num) > 255) {
                continue;
            }
            candidates.push_back(num);
            dfs(s, idx + i, candidates, res);
            candidates.pop_back();
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 枚举
// 2022-11-14 submission
// 145/145 cases passed
// Runtime: 6 ms, faster than 39.25% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 68.26% of cpp online submissions.
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a = 1; a < 4; ++a)
            for (int b = 1; b < 4; ++b)
                for (int c = 1; c < 4; ++c)
                    for (int d = 1; d < 4; ++d)
                        if (a + b + c + d == s.size()) {
                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a + b, c));
                            int D = stoi(s.substr(a + b + c, d));
                            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                                string t = to_string(A) + "." + to_string(B) + "." + to_string(C) +
                                           "." + to_string(D);
                                if (t.size() == s.size() + 3) {
                                    res.push_back(t);
                                }
                            }
                        }
        return res;
    }
};
// @lc code=end
