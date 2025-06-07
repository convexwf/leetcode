/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
// 1. 极值统计
// 2020-07-14 submission
// 320/320 cases passed
// Runtime: 4 ms, faster than 88.40% of cpp online submissions.
// Memory Usage: 14.1 MB, less than 71.67% of cpp online submissions.
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) {
            return 0;
        }
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 双指针
// 2022-11-17 submission
// 322/322 cases passed
// Runtime: 42 ms, faster than 26.88% of cpp online submissions.
// Memory Usage: 19.7 MB, less than 82% of cpp online submissions.
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, res = 0;
        while (l < r) {
            int lower = height[(height[l] < height[r]) ? l++ : r--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 单调递减栈
// 2022-11-17 submission
// 322/322 cases passed
// Runtime: 37 ms, faster than 42.75% of cpp online submissions.
// Memory Usage: 20.3 MB, less than 46.03% of cpp online submissions.
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            }
            else {
                int t = st.top();
                st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};
// @lc code=end
