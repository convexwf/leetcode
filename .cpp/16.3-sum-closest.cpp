/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
// 2023-02-28 submission
// 98/98 cases passed
// Runtime: 41 ms, faster than 93.95% of cpp online submissions.
// Memory Usage: 10.2 MB, less than 85% of cpp online submissions.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestVal = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int lval = 0, rval = 0, pivot = 0, cur_sum = 0;
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            pivot = nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int left = i + 1, right = (int)nums.size() - 1; left < right;) {
                cur_sum = nums[left] + nums[right] + pivot;
                if (cur_sum == target) return target;
                if (cur_sum > target) right--;
                if (cur_sum < target) left++;
                if (abs(target - cur_sum) < abs(target - closestVal)) closestVal = cur_sum;
            }
        }
        return closestVal;
    }
};
// @lc code=end
