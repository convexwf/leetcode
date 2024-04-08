/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
// 1. 栈+字符串分割
// 2022-07-27 submission
// 257/257 cases passed
// Runtime: 19 ms, faster than 11.64% of cpp online submissions.
// Memory Usage: 9.6 MB, less than 60.38% of cpp online submissions.
class Solution {
public:
    string simplifyPath(string path) {
        string res, t;
        stringstream ss(path);
        vector<string> v;
        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") continue;
            if (t == ".." && !v.empty())
                v.pop_back();
            else if (t != "..")
                v.push_back(t);
        }
        for (string s : v) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
