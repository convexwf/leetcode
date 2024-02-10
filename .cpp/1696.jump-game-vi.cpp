/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
// 2023-02-28 submission
// 72/72 cases passed
// Runtime: 189 ms, faster than 75.09% of C++ online submissions.
// Memory Usage: 77.9 MB, less than 89.15% of C++ online submissions.
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        q.push_back({0, nums[0]});
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            while (!q.empty() && i - k > q.front().first) {
                q.pop_front();
            }
            ans = q.front().second + nums[i];
            while (!q.empty() && ans >= q.back().second) {
                q.pop_back();
            }
            q.push_back({i, ans});
        }
        return ans;
    }
};
// @lc code=end
