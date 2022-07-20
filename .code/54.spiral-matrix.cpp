/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (42.41%)
 * Likes:    7974
 * Dislikes: 873
 * Total Accepted:    789.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

// @lc code=start
// 2022-07-20 submission
// 23/23 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7 MB, less than 30.15% of C++ online submissions.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>{};
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> traj;
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        while (traj.size() < rows * cols) {
            for (int i = left; i <= right; i++) {
                traj.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; i++) {
                traj.push_back(matrix[i][right]);
            }
            for (int i = right - 1; i >= left && top < bottom; i--) {
                traj.push_back(matrix[bottom][i]);
            }
            for (int i = bottom - 1; i > top && left < right; i--) {
                traj.push_back(matrix[i][left]);
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return traj;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-20 submission
// 23/23 cases passed
// Runtime: 5 ms, faster than 15.91% of C++ online submissions.
// Memory Usage: 7 MB, less than 30.15% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>{};
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> traj;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int x = 0, y = -1, di = 0;
        for (int i = 0; i < rows * cols; i++) {
            if (0 > x + direction[di][0] || x + direction[di][0] >= rows ||
                0 > y + direction[di][1] || y + direction[di][1] >= cols ||
                visited[x + direction[di][0]][y + direction[di][1]])
                di = (di + 1) % 4;
            x += direction[di][0];
            y += direction[di][1];
            visited[x][y] = true;
            traj.push_back(matrix[x][y]);
        }
        return traj;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-20 submission
// 23/23 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.8 MB, less than 91.91% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>{};
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> traj;
        int x = 0, y = -1, di = 0;
        for (int i = 0; i < rows * cols; i++) {
            // 边界判断，已访问判断
            if (0 > x + direction[di][0] || x + direction[di][0] >= rows ||
                0 > y + direction[di][1] || y + direction[di][1] >= cols ||
                matrix[x + direction[di][0]][y + direction[di][1]] == 0) {
                di = (di + 1) % 4;
            }

            x += direction[di][0];
            y += direction[di][1];
            traj.push_back(matrix[x][y]);
            matrix[x][y] = 0;
        }
        return traj;
    }
};
// @lc code=end