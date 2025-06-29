/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
// 1. 面积计算
// 2020-09-15 submission
// 74/74 cases passed
// Runtime: 38 ms, faster than 94.58% of cpp online submissions.
// Memory Usage: 12.1 MB, less than 94.07% of cpp online submissions.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int rows = matrix.size(), cols = matrix[0].size();

        int max_area = 0;
        vector<int> left_seq(cols, INT_MAX);
        vector<int> right_seq(cols, INT_MAX);
        vector<int> height(cols, 0);
        int continous = 0;

        for (int i = 0; i < rows; i++) {
            continous = 0;
            for (int j = cols - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    continous++;
                }
                else {
                    continous = 0;
                }
                height[j] = continous == 0 ? 0 : height[j] + 1;
                right_seq[j] = right_seq[j] == 0 ? continous : min(right_seq[j], continous);
            }

            continous = 0;
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    continous++;
                }
                else {
                    continous = 0;
                }
                left_seq[j] = left_seq[j] == 0 ? continous : min(left_seq[j], continous);
                max_area = max(max_area, height[j] * (left_seq[j] + right_seq[j] - 1));
            }
        }

        return max_area;
    }
};
// @lc code=end

// @lc code=start
// 2. 矩形枚举
// 2023-02-02 submission
// 74/74 cases passed
// Runtime: 88 ms, faster than 29.33% of cpp online submissions.
// Memory Usage: 13 MB, less than 83.56% of cpp online submissions.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> h_max(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') continue;
                if (j > 0) {
                    h_max[i][j] = h_max[i][j - 1] + 1;
                }
                else {
                    h_max[i][j] = 1;
                }
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

// @lc code=start
// 3. 单调递增栈+面积计算
// 2025-06-03 submission
// 74/74 cases passed
// Runtime: 7 ms, faster than 66.08% of cpp online submissions.
// Memory Usage: 19.5 MB, less than 42.59% of cpp online submissions.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for (const vector<char>& row : matrix) {
            for (int j = 0; j < n; ++j) {
                if (row[j] == '1') {
                    ++heights[j];
                }
                else {
                    heights[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};
// @lc code=end
