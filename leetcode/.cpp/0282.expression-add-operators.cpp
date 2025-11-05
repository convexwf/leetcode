/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
// 1. 递归
// 2023-10-01 submission
// 23/23 cases passed
// Runtime: 603 ms, faster than 47.81% of cpp online submissions.
// Memory Usage: 124.7 MB, less than 51.78% of cpp online submissions.
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(res, "", 0, 0, 0, num, target);
        return res;
    }
    void dfs(vector<string>& res, string path, int pos, long cur, long pre, string& num,
             int target) {
        if (pos == num.size() && cur == target) {
            res.push_back(path);
            return;
        }
        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break;
            string s = num.substr(pos, i - pos + 1);
            long n = stol(s);
            if (pos == 0) {
                dfs(res, path + s, i + 1, n, n, num, target);
            }
            else {
                dfs(res, path + "+" + s, i + 1, cur + n, n, num, target);
                dfs(res, path + "-" + s, i + 1, cur - n, -n, num, target);
                dfs(res, path + "*" + s, i + 1, cur - pre + pre * n, pre * n, num, target);
            }
        }
    }
};
// @lc code=end
