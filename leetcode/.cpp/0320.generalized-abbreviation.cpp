/*
 * @lc app=leetcode id=320 lang=cpp
 *
 * [320] Generalized Abbreviation
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;

        function<void(int, string)> dfs = [&](int i, string cur) {
            if (i >= word.size()) {
                res.push_back(cur);
                return;
            }

            dfs(i + 1, cur + word[i]);
            for (int k = 1; i + k <= word.size(); ++k) {
                dfs(i + k, cur + to_string(k));
            }
        };

        dfs(0, "");
        return res;
    }
};
// @lc code=end
