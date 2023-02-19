/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (46.35%)
 * Likes:    9840
 * Dislikes: 168
 * Total Accepted:    590K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given an integer array nums, return true if you can partition the array into
 * two subsets such that the sum of the elements in both subsets is equal or
 * false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
// 2023-02-13 submission
// 141/141 cases passed
// Runtime: 142 ms, faster than 87.8% of C++ online submissions.
// Memory Usage: 9.8 MB, less than 89.85% of C++ online submissions.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};
// @lc code=end

// @lc code=start
// 2023-02-13 submission
// 141/141 cases passed
// Runtime: 16 ms, faster than 99.09% of C++ online submissions.
// Memory Usage: 9.7 MB, less than 94.94% of C++ online submissions.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int num : nums) {
            bits |= (bits << num);
        }
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};
// @lc code=end