/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
// 1. 模拟
// 2020-09-29 submission
// 27/27 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 19.1% of cpp online submissions.
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int cur_len = 0;
        vector<string> cur_words;
        for (int i = 0; i < words.size(); ++i) {
            if (cur_len + cur_words.size() + words[i].size() <= maxWidth) {
                cur_len += words[i].size();
                cur_words.push_back(words[i]);
            }
            else {
                int space = maxWidth - cur_len;
                int n = cur_words.size();
                if (n == 1) {
                    res.push_back(cur_words[0] + string(space, ' '));
                }
                else {
                    int avg_space = space / (n - 1);
                    int extra_space = space % (n - 1);
                    string line = cur_words[0];
                    for (int j = 1; j < n; ++j) {
                        line += string(avg_space, ' ');
                        if (j <= extra_space) {
                            line += ' ';
                        }
                        line += cur_words[j];
                    }
                    res.push_back(line);
                }
                cur_len = words[i].size();
                cur_words.clear();
                cur_words.push_back(words[i]);
            }
        }
        string line = cur_words[0];
        for (int i = 1; i < cur_words.size(); ++i) {
            line += ' ' + cur_words[i];
        }
        line += string(maxWidth - line.size(), ' ');
        res.push_back(line);
        return res;
    }
};
// @lc code=end
