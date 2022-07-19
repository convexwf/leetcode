/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.64%)
 * Likes:    6313
 * Dislikes: 310
 * Total Accepted:    836.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 *
 * Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 *
 *
 */

// @lc code=start
// 2022-07-18 submission
// 281/281 cases passed
// Runtime: 491 ms, faster than 43.96% of C++ online submissions.
// Memory Usage: 23.1 MB, less than 44.65% of C++ online submissions.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestVal = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int lval = 0, rval = 0, pivot = 0, cur_sum = 0;
        for(int i = 0; i < (int)nums.size() - 2; i++) {
            pivot = nums[i];
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int left = i + 1, right = (int)nums.size() - 1; left < right;) {
                cur_sum = nums[left] + nums[right] + rest;
                if(curr_sum == target) return target;
                if(curr_sum > target) right--;
                if(curr_sum < target) left++;
                if(abs(target - curr_sum) < abs(target - closestVal))
                    closestVal=curr_sum;
            }
        }
        return closestVal;
    }
};
// @lc code=end
