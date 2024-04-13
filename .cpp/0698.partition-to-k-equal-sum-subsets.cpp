/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> bucket(k, 0);
        return dfs(nums, bucket, 0, target);
    }

    bool dfs(vector<int>& nums, vector<int>& bucket, int idx, int target) {
        if (idx == nums.size()) {
            return true;
        }
        for (int i = 0; i < bucket.size(); ++i) {
            if (bucket[i] + nums[idx] <= target) {
                bucket[i] += nums[idx];
                if (dfs(nums, bucket, idx + 1, target)) return true;
                bucket[i] -= nums[idx];
            }
        }
        return false;
    }
};
// @lc code=end
