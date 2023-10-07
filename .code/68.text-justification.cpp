/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
// 2020-09-29 submission
// 27/27 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 19.1% of C++ online submissions.
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        vector<string> cur;
        int cur_len = 0;
        for (int i = 0; i < words.size();) {
            bool flag = (words[i].length() + cur_len <= maxWidth);
            if (flag) {
                cur_len += (words[i].length() + 1);
                cur.push_back(words[i]);
                i++;
            }
            if (!flag && i < words.size()) {
                cur_len = maxWidth-cur_len+cur.size();
                string to_add = cur[0];
                if (cur.size() == 1) to_add.append(cur_len, ' ');
                for (int j = 1; j < cur.size(); j++) {
                    to_add.append(cur_len/(cur.size()-1)+(j<=cur_len%(cur.size()-1)), ' ');
                    to_add.append(cur[j]);
                }
                res.push_back(to_add);
                cur_len = 0;
                cur.clear();
            }
            if (i == words.size()) {
                string to_add = cur[0];
                for (int j = 1; j < cur.size(); j++) {
                    to_add.append(" ");
                    to_add.append(cur[j]);
                }
                to_add.append(maxWidth-to_add.length(), ' ');
                res.push_back(to_add);
            }
        }
        return res;
    }
};
// @lc code=end
