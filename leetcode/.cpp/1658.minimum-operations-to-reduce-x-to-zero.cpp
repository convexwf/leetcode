/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
// 1. 前缀和+哈希表
// 2025-04-09 submission
// 97/97 cases passed
// Runtime: 224 ms, faster than 14.59% of cpp online submissions.
// Memory Usage: 170.6 MB, less than 15.16% of cpp online submissions.
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) {
            return -1;
        }

        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = -1; // 前缀和为 0 的位置
        int max_len = -1;
        int cur_sum = 0;

        for (int i = 0; i < n; ++i) {
            cur_sum += nums[i];
            if (!prefix_sum.count(cur_sum)) {
                prefix_sum[cur_sum] = i;
            }
            if (prefix_sum.count(cur_sum - target)) {
                max_len = max(max_len, i - prefix_sum[cur_sum - target]);
            }
        }

        return max_len == -1 ? -1 : n - max_len;
    }
};
// @lc code=end
