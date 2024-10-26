/*
 * @lc app=leetcode id=308 lang=cpp
 *
 * [308] Range Sum Query 2D - Mutable
 */

// @lc code=start
// 1. 树状数组
class BinaryIndexTree {
public:
    BinaryIndexTree(int m, int n)
        : m(m),
          n(n),
          c(m + 1, vector<int>(n + 1, 0)),
          a(m, vector<int>(n, 0)) {
    }

    void update(int row, int col, int val) {
        int delta = val - a[row][col];
        a[row][col] = val;
        for (int i = row + 1; i <= m; i += lowbit(i)) {
            for (int j = col + 1; j <= n; j += lowbit(j)) {
                c[i][j] += delta;
            }
        }
    }

    int query(int row, int col) {
        int res = 0;
        for (int i = row + 1; i > 0; i -= lowbit(i)) {
            for (int j = col + 1; j > 0; j -= lowbit(j)) {
                res += c[i][j];
            }
        }
        return res;
    }

    int lowbit(int x) {
        return x & -x;
    }

private:
    int m, n;
    vector<vector<int>> c;
    vector<vector<int>> a;
};

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : m(matrix.size()), n(matrix[0].size()), bit(m, n) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bit.update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        bit.update(row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return bit.query(row2, col2) - bit.query(row1 - 1, col2) - bit.query(row2, col1 - 1) +
               bit.query(row1 - 1, col1 - 1);
    }

private:
    int m, n;
    BinaryIndexTree bit;
};
// @lc code=end
