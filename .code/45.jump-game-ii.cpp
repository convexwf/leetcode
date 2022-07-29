/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (37.88%)
 * Likes:    8801
 * Dislikes: 318
 * Total Accepted:    654.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * You can assume that you can always reach the last index.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
// 2022-07-28 submission
// 109/109 cases passed
// Runtime: 23 ms, faster than 72.87% of C++ online submissions.
// Memory Usage: 16.5 MB, less than 96.6% of C++ online submissions.
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int res = 1;
        int pre = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > pre) {
                pre = cur;
                ++res;
            }
            cur = max(cur, i + nums[i]);
            if (cur >= nums.size() - 1) break;
        }
        return res;
    }
};
// @lc code=end