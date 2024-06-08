/*
 * @lc app=leetcode id=247 lang=cpp
 *
 * [247] Strobogrammatic Number II
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return dfs(n, n);
    }

    vector<string> dfs(int n, int m) {
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};
        vector<string> res;
        vector<string> t = dfs(n - 2, m);
        for (const string& a : t) {
            if (n != m) res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};
// @lc code=end
