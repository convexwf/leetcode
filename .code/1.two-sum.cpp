/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (48.62%)
 * Likes:    32485
 * Dislikes: 1032
 * Total Accepted:    6.7M
 * Total Submissions: 13.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 * 
 * 
 * 
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

// @lc code=start
// 2022-05-30 submission
// 57/57 cases passed
// Runtime: 19 ms, faster than 59.18% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 45.93% of C++ online submissions.
// 2022-05-30 submission
// 57/57 cases passed
// Runtime: 12 ms, faster than 83.93% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 29.71% of C++ online submissions.
// 2022-05-30 submission
// 57/57 cases passed
// Runtime: 22 ms, faster than 52.06% of C++ online submissions.
// Memory Usage: 10.8 MB, less than 45.93% of C++ online submissions.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) 
                return vector<int>{m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end