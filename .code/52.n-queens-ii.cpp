/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
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