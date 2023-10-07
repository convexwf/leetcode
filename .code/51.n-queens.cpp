/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
// 2022-07-20 submission
// 9/9 cases passed
// Runtime: 14 ms, faster than 41.51% of C++ online submissions.
// Memory Usage: 7.5 MB, less than 47.79% of C++ online submissions.
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> result;
        vector<vector<string>> chess_results;
        vector<int> temp(n, 0);
        if (n == 1) {
            chess_results.push_back(vector<string>{"Q"});
            return chess_results;
        }
        else if (n >= 4) {
            place(0, n, temp, result);
            print_chess(result, chess_results);
        }
        return chess_results;
    }

    bool find(int row, int col, vector<int>& curr) {
        for (int i = 0; i < row; i++) {
            if (curr[i] == col || abs(i - row) == abs(col - curr[i]))
                return false;
        }
        return true;
    }

    void place(int k, int n, vector<int>& curr, vector<vector<int>>& result) {
        for (int i = 0; i < n; i++) {
            if (find(k, i, curr)) {
                curr[k] = i;
                if (k == n - 1)
                    result.push_back(curr);
                else
                    place(k + 1, n, curr, result);
            }
        }
    }

    void print_chess(vector<vector<int>>& result,
                     vector<vector<string>>& chess_results) {
        int col = 0;
        string temp = "";
        for (int i = 0; i < result.size(); i++) {
            int n = result[i].size();
            chess_results.push_back(vector<string>{});
            for (int j = 0; j < n; j++) {
                col = result[i][j];
                temp = "";
                for (int k = 0; k < col; k++) temp += '.';
                temp += 'Q';
                for (int k = col + 1; k < n; k++) temp += '.';
                chess_results[i].push_back(temp);
            }
        }
    }
};
// @lc code=end