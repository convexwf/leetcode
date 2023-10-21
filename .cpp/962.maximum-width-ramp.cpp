/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
// 2023-10-17 submission
// 98/98 cases passed
// Runtime: 42 ms, faster than 35.79% of cpp online submissions.
// Memory Usage:  MB, less than 28.23% of cpp online submissions.
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};
// @lc code=end
