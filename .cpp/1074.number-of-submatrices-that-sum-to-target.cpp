/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
// 1. 枚举上下边界+前缀和+哈希表
// 2023-12-27 submission
// 40/40 cases passed
// Runtime: 797 ms, faster than 28.02% of cpp online submissions.
// Memory Usage: 276.4 MB, less than 11.81% of cpp online submissions.
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n);
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    sum[k] += matrix[j][k];
                }
                res += subarraySum(sum, target);
            }
        }
        return res;
    }

private:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dp{{0, 1}};
        int sum = 0, res = 0;
        for (int num : nums) {
            sum += num;
            res += dp[sum - k];
            ++dp[sum];
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 枚举左右边界+前缀和+哈希表
// 2023-12-27 submission
// 40/40 cases passed
// Runtime: 790 ms, faster than 29.95% of cpp online submissions.
// Memory Usage: 253.7 MB, less than % of cpp online submissions.
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unordered_map<int, int> cntMap{{0, 1}};
                int cur = 0;
                for (int k = 0; k < m; ++k) {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += cntMap[cur - target];
                    ++cntMap[cur];
                }
            }
        }
        return res;
    }
};
// @lc code=end
