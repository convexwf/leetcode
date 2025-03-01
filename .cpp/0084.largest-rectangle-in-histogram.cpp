/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
// 1. 局部峰值查找
// Time Limit Exceeded
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && heights[i] <= heights[i + 1]) {
                continue;
            }
            int minHeight = heights[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, heights[j]);
                res = max(res, minHeight * (i - j + 1));
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 单调递增栈
// 2022-11-17 submission
// 98/98 cases passed
// Runtime: 302 ms, faster than 72.31% of cpp online submissions.
// Memory Usage: 75.3 MB, less than 91.47% of cpp online submissions.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top();
                st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
