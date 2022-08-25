/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (70.09%)
 * Likes:    2610
 * Dislikes: 227
 * Total Accepted:    270.7K
 * Total Submissions: 386.2K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

// @lc code=start
// 2022-07-20 submission
// 9/9 cases passed
// Runtime: 3 ms, faster than 86.88% of C++ online submissions.
// Memory Usage: 6.1 MB, less than 77.55% of C++ online submissions.
class Solution {
public:
    int totalNQueens(int n) {
        int success = 0;
        vector<int> temp(n, 0);
        place(0, n, temp, success);
        return success;
    }

    bool find(int row, int col, vector<int>& curr) {
        for(int i = 0; i < row; i++) {
            if(curr[i] == col || abs(i-row) == abs(curr[i]-col))
                return false;
        }
        return true;
    }

    void place(int k, int n, vector<int>& curr, int &success) {
        for(int i = 0; i < n; i++) {
            if(find(k, i, curr)) {
                curr[k] = i;
                if(k == n-1) success++;
                else place(k+1, n, curr, success);
            }
        }
    }

};
// @lc code=end