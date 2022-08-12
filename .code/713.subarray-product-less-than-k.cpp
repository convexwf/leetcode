/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 *
 * https://leetcode.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (44.51%)
 * Likes:    4373
 * Dislikes: 141
 * Total Accepted:    186.1K
 * Total Submissions: 418.1K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * Given an array of integers nums and an integer k, return the number of
 * contiguous subarrays where the product of all the elements in the subarray
 * is strictly less than k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,5,2,6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are:
 * [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly
 * less than k.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3], k = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
 *
 *
 */

// @lc code=start
// 2022-08-12 submission
// 97/97 cases passed
// Runtime: 141 ms, faster than 42.25% of C++ online submissions.
// Memory Usage: 61.1 MB, less than 93.31% of C++ online submissions.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            prod *= nums[right];
            while (left <= right && prod >= k) prod /= nums[left++];
            res += right - left + 1;
        }
        return res;
    }
};
// @lc code=end