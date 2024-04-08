/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
// 2023-01-14 submission
// 78/78 cases passed
// Runtime: 936 ms, faster than 5.03% of cpp online submissions.
// Memory Usage: 20.8 MB, less than 74.69% of cpp online submissions.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> v(matrix[i].size(), 0);
            for (int j = i; j < matrix.size(); ++j) {
                for (int k = 0; k < matrix[j].size(); ++k) {
                    if (matrix[j][k] == '1') ++v[k];
                }
                res = max(res, getSquareArea(v, j - i + 1));
            }
        }
        return res;
    }

    int getSquareArea(vector<int>& v, int k) {
        if (v.size() < k) return 0;
        int count = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != k)
                count = 0;
            else
                ++count;
            if (count == k) return k * k;
        }
        return 0;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 78/78 cases passed
// Runtime: 1191 ms, faster than 5.03% of cpp online submissions.
// Memory Usage: 20.9 MB, less than 52.59% of cpp online submissions.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                int t = matrix[i][j] - '0';
                if (i > 0) t += sum[i - 1][j];
                if (j > 0) t += sum[i][j - 1];
                if (i > 0 && j > 0) t -= sum[i - 1][j - 1];
                sum[i][j] = t;
                int cnt = 1;
                for (int k = min(i, j); k >= 0; --k) {
                    int d = sum[i][j];
                    if (i - cnt >= 0) d -= sum[i - cnt][j];
                    if (j - cnt >= 0) d -= sum[i][j - cnt];
                    if (i - cnt >= 0 && j - cnt >= 0) d += sum[i - cnt][j - cnt];
                    if (d == cnt * cnt) res = max(res, d);
                    ++cnt;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 78/78 cases passed
// Runtime: 86 ms, faster than 90.74% of cpp online submissions.
// Memory Usage: 21 MB, less than 20.22% of cpp online submissions.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 78/78 cases passed
// Runtime: 76 ms, faster than 98.28% of cpp online submissions.
// Memory Usage: 18.6 MB, less than 95.7% of cpp online submissions.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0, pre = 0;
        vector<int> dp(m + 1, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i <= m; ++i) {
                int t = dp[i];
                if (matrix[i - 1][j] == '1') {
                    dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                    res = max(res, dp[i]);
                }
                else {
                    dp[i] = 0;
                }
                pre = t;
            }
        }
        return res * res;
    }
};
// @lc code=end
