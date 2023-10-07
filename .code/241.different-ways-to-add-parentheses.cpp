/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
// 2022-11-17 submission
// 25/25 cases passed
// Runtime: 3 ms, faster than 83.11% of C++ online submissions.
// Memory Usage: 11.3 MB, less than 47.72% of C++ online submissions.
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (input[i] == '+') res.push_back(left[j] + right[k]);
                        else if (input[i] == '-') res.push_back(left[j] - right[k]);
                        else res.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 25/25 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7.2 MB, less than 90.17% of C++ online submissions.
class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string input) {
        if (memo.count(input)) return memo[input];
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (input[i] == '+') res.push_back(left[j] + right[k]);
                        else if (input[i] == '-') res.push_back(left[j] - right[k]);
                        else res.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        memo[input] = res;
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 25/25 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.7 MB, less than 97.37% of C++ online submissions.
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return {};
        vector<string> ops;
        int n = input.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && isdigit(input[j])) ++j;
            ops.push_back(input.substr(i, j - i));
            if (j < n) ops.push_back(input.substr(j, 1));
            i = j;
        }
        int cnt = (ops.size() + 1) / 2;
        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(cnt, vector<int>()));
        for (int i = 0; i < cnt; ++i) dp[i][i].push_back(stoi(ops[i * 2]));
        for (int len = 0; len < cnt; ++len) {
            for (int i = 0; i < cnt - len; ++i) {
                for (int j = i; j < i + len; ++j) {
                    vector<int> left = dp[i][j], right = dp[j + 1][i + len];
                    string op = ops[j * 2 + 1];
                    for (int num1 : left) {
                        for (int num2 : right) {
                            if (op == "+") dp[i][i + len].push_back(num1 + num2);
                            else if (op == "-") dp[i][i + len].push_back(num1 - num2);
                            else dp[i][i + len].push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        return dp[0][cnt - 1];
    }
};
// @lc code=end