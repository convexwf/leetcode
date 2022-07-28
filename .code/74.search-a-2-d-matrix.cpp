/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (45.63%)
 * Likes:    8569
 * Dislikes: 290
 * Total Accepted:    886.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * Write an efficient algorithm that searches for a value target in an m x n
 * integer matrix matrix. This matrix has the following properties:
 *
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 *
 *
 */

// @lc code=start
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 10 ms, faster than 26.38% of C++ online submissions.
// Memory Usage: 9.6 MB, less than 51.72% of C++ online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 15 ms, faster than 6.81% of C++ online submissions.
// Memory Usage: 9.6 MB, less than 5.1% of C++ online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = (int)matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-27 submission
// 133/133 cases passed
// Runtime: 7 ms, faster than 53.15% of C++ online submissions.
// Memory Usage: 9.5 MB, less than 51.72% of C++ online submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (r <= 0) return false;

        int ridx = r - 1;
        l = 0;
        r = n;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (matrix[ridx][mid] == target)
                return true;
            else if (matrix[ridx][mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return false;
    }
};
// @lc code=end
