/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (43.39%)
 * Likes:    7123
 * Dislikes: 114
 * Total Accepted:    307.2K
 * Total Submissions: 708K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest
 * rectangle containing only 1's and return its area.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 6
 * Explanation: The maximal rectangle is shown in the above picture.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [["0"]]
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [["1"]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * rows == matrix.length
 * cols == matrix[i].length
 * 1 <= row, cols <= 200
 * matrix[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start
// 2020-09-15 submission
// 74/74 cases passed
// Runtime: 38 ms, faster than 94.58% of C++ online submissions.
// Memory Usage: 12.1 MB, less than 94.07% of C++ online submissions.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int max_area = 0;
        vector<int> left_seq(cols, INT_MAX);
        vector<int> right_seq(cols, INT_MAX);
        vector<int> height(cols, 0);
        int continous = 0;

        for (int i = 0; i < rows; i++) {
            continous = 0;
            for (int j = cols-1; j >= 0; j--) {
                if (matrix[i][j] == '1') continous++;
                else continous = 0;
                height[j] = continous == 0 ? 0 : height[j] + 1;
                right_seq[j] = right_seq[j] == 0 ? continous : min(right_seq[j], continous);
            }

            continous = 0;
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') continous++;
                else continous = 0;
                left_seq[j] = left_seq[j] == 0 ? continous : min(left_seq[j], continous);
                max_area = max(max_area, height[j]*(left_seq[j]+right_seq[j]-1));
            }
        }

        return max_area;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-02 submission
// 74/74 cases passed
// Runtime: 88 ms, faster than 29.33% of C++ online submissions.
// Memory Usage: 13 MB, less than 83.56% of C++ online submissions.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> h_max(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') continue;
                if (j > 0) h_max[i][j] = h_max[i][j - 1] + 1;
                else h_max[i][0] = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (h_max[i][j] == 0) continue;
                int mn = h_max[i][j];
                res = max(res, mn);
                for (int k = i - 1; k >= 0 && h_max[k][j] != 0; --k) {
                    mn = min(mn, h_max[k][j]);
                    res = max(res, mn * (i - k + 1));
                }
            }
        }
        return res;
    }
};
// @lc code=end