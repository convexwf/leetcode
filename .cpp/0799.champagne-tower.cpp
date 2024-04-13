/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
// 1. 模拟
// 2020-10-27 submission
// 312/312 cases passed
// Runtime: 3 ms, faster than 86.83% of cpp online submissions.
// Memory Usage: 16.4 MB, less than 37.47% of cpp online submissions.
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> arr(query_row + 1, vector<double>(query_row + 1, 0));
        arr[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (arr[i][j] > 1) {
                    arr[i + 1][j] += (arr[i][j] - 1) / 2;
                    arr[i + 1][j + 1] += (arr[i][j] - 1) / 2;
                    arr[i][j] = 1;
                }
            }
        }
        return min(1.0, arr[query_row][query_glass]);
    }
};
// @lc code=end

// @lc code=start
// 2. 模拟+一维数组
// 2024-03-01 submission
// 312/312 cases passed
// Runtime: 5 ms, faster than 65.22% of cpp online submissions.
// Memory Usage: 8.6 MB, less than 75.96% of cpp online submissions.
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // length of arr is query_row + 2
        // because we need to store the last row
        vector<double> arr(query_row + 2, 0);
        arr[0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            for (int j = i; j >= 0; --j) {
                arr[j] = max(0.0, (arr[j] - 1) / 2);
                arr[j + 1] += arr[j];
            }
        }
        return min(1.0, arr[query_glass]);
    }
};
// @lc code=end
