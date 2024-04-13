/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start
// 1. 双 multiset
// 2023-11-17 submission
// 43/43 cases passed
// Runtime: 125 ms, faster than 47.28% of cpp online submissions.
// Memory Usage: 46.1 MB, less than 33.43% of cpp online submissions.
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small, large;
        vector<double> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (small.count(nums[i - k])) {
                    small.erase(small.find(nums[i - k]));
                }
                else {
                    large.erase(large.find(nums[i - k]));
                }
            }
            if (small.size() <= large.size()) {
                if (large.empty() || nums[i] <= *large.begin()) {
                    small.insert(nums[i]);
                }
                else {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            }
            else {
                if (nums[i] >= *small.rbegin()) {
                    large.insert(nums[i]);
                }
                else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }
            if (i >= k - 1) {
                if (k & 1) {
                    res.push_back(*small.rbegin());
                }
                else {
                    res.push_back(((double)*small.rbegin() + *large.begin()) / 2);
                }
            }
        }
        return res;
    }
};
// @lc code=end
