/*
 * @lc app=leetcode id=248 lang=cpp
 *
 * [248] Strobogrammatic Number III
 */

// @lc code=start
// 1. 递归+找规律
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        for (int i = low.size(); i <= high.size(); ++i) {
            vector<string> cur = dfs(i, i);
            for (string& s : cur) {
                if ((s.size() == low.size() && s < low) || (s.size() == high.size() && s > high)) {
                    continue;
                }
                ++res;
            }
        }
        return res;
    }

    vector<string> dfs(int u, int n) {
        if (u == 0) {
            return {""};
        }
        if (u == 1) {
            return {"0", "1", "8"};
        }
        vector<string> res;
        vector<string> t = dfs(u - 2, n);
        for (string& s : t) {
            if (u != n) {
                res.push_back("0" + s + "0");
            }
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8");
            res.push_back("9" + s + "6");
        }
        return res;
    }
};
// @lc code=end
