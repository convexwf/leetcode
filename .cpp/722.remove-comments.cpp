/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */

// @lc code=start
// 2023-07-05 submission
// 54/54 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 99.08% of cpp online submissions.
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string line;
        bool in_block = false;
        for (string& s : source) {
            for (int i = 0; i < s.size(); ++i) {
                // if not in block and "//" is found, break
                if (!in_block && i + 1 < s.size() && s[i] == '/' && s[i + 1] == '/') break;
                // if not in block and "/*" is found, set in_block to true
                else if (!in_block && i + 1 < s.size() && s[i] == '/' && s[i + 1] == '*') {
                    in_block = true;
                    ++i
                };
                // if in block and "*/" is found, set in_block to false
                else if (in_block && i + 1 < s.size() && s[i] == '*' && s[i + 1] == '/') {
                    in_block = false;
                    ++i;
                }
                else if (!in_block)
                    line.push_back(s[i]);
            }
            if (!in_block && line.size()) {
                res.push_back(line);
                line.clear()
            };
        }
        return res;
    }
};
// @lc code=end
