/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
// 2023-02-28 submission
// 102/102 cases passed
// Runtime: 41 ms, faster than 93.95% of cpp online submissions.
// Memory Usage: 10.2 MB, less than 85% of cpp online submissions.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return sum;
                if (abs(sum - target) < abs(res - target)) res = sum;
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return res;
    }
};
// @lc code=end
