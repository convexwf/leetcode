/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
// 1. 滑动窗口+有序集合
// 2023-01-31 submission
// 49/49 cases passed
// Runtime: 210 ms, faster than 74.88% of cpp online submissions.
// Memory Usage: 79.1 MB, less than 43.32% of cpp online submissions.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            auto it = window.lower_bound((long)nums[i] - t);
            if (it != window.end() && *it <= (long)nums[i] + t) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end
