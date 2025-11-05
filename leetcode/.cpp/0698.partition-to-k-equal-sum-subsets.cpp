/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
// 1. 回溯
// 2025-06-04 submission
// 164/164 cases passed
// Runtime: 1 ms, faster than 85.91% of cpp online submissions.
// Memory Usage: 13.3 MB, less than 30.86% of cpp online submissions.
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k, n = nums.size();

        vector<int> bucket(k);
        function<bool(int)> dfs = [&](int index) {
            if (index == n) {
                return true;
            }
            for (int i = 0; i < k; ++i) {
                if (i > 0 && bucket[i] == bucket[i - 1]) {
                    continue; // Skip duplicate buckets
                }
                bucket[i] += nums[index];
                if (bucket[i] <= target && dfs(index + 1)) {
                    return true;
                }
                bucket[i] -= nums[index]; // Backtrack
            }
            return false;
        };
        sort(nums.rbegin(), nums.rend()); // Sort in descending order for optimization
        return dfs(0);
    }
};
// @lc code=end
