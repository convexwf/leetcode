/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
// 1. 记忆化搜索
// 2022-11-17 submission
// 25/25 cases passed
// Runtime: 3 ms, faster than 83.11% of cpp online submissions.
// Memory Usage: 11.3 MB, less than 47.72% of cpp online submissions.
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        function<vector<int>(string)> dfs = [&](string input) {
            if (memo.count(input)) {
                return memo[input];
            }
            vector<int> res;
            for (int i = 0; i < input.size(); ++i) {
                if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                    vector<int> left = dfs(input.substr(0, i));
                    vector<int> right = dfs(input.substr(i + 1));
                    for (int j = 0; j < left.size(); ++j) {
                        for (int k = 0; k < right.size(); ++k) {
                            if (input[i] == '+') {
                                res.push_back(left[j] + right[k]);
                            }
                            else if (input[i] == '-') {
                                res.push_back(left[j] - right[k]);
                            }
                            else {
                                res.push_back(left[j] * right[k]);
                            }
                        }
                    }
                }
            }
            if (res.empty()) {
                res.push_back(stoi(input));
            }

            return memo[input] = res;
        };
        return dfs(expression);
    }
};
// @lc code=end
