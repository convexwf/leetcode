/*
 * @lc app=leetcode id=555 lang=cpp
 *
 * [555] Split Concatenated Strings
 */

// @lc code=start
// 1. 贪心算法
class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        for (string& s : strs) {
            string t = s;
            reverse(t.begin(), t.end());
            s = max(s, t);
        }
        string res;
        for (int i = 0; i < n; ++i) {
            const string& s = strs[i];
            string t;
            for (int j = i + 1; j < n; ++j) {
                t += strs[j];
            }
            for (int j = 0; j < i; ++j) {
                t += strs[j];
            }
            for (int j = 0; j < s.size(); ++j) {
                string a = s.substr(j);
                string b = s.substr(0, j);
                string c = a + t + b;
                res = max(res, c);
                reverse(a.begin(), a.end());
                reverse(b.begin(), b.end());
                c = a + t + b;
                res = max(res, c);
            }
        }
        return res;
    }
};
// @lc code=end
