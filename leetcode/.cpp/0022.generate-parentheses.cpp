/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
// 1. 递归
// 2023-01-30 submission
// 8/8 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 96.84% of cpp online submissions.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        helper(res, cur, n, n);
        return res;
    }

    void helper(vector<string>& res, string cur, int lp, int rp) {
        if (lp == 0) {
            res.push_back(cur + string(rp - lp, ')'));
            return;
        }
        helper(res, cur + "(", lp - 1, rp);
        if (lp < rp) helper(res, cur + ")", lp, rp - 1);
    }
};
// @lc code=end

// @lc code=start
// 2. 构造法
// 2023-01-30 submission
// 8/8 cases passed
// Runtime: 3 ms, faster than 83.32% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 95.62% of cpp online submissions.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> st;
        if (n == 0) {
            return {""};
        }
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (string a : pre) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        string tmp = a.substr(0, i + 1) + "()" + a.substr(i + 1);
                        st.insert(tmp);
                    }
                }
                st.insert("()" + a);
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};
// @lc code=end
