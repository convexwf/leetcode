/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (36.74%)
 * Likes:    11975
 * Dislikes: 3624
 * Total Accepted:    869.6K
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3]'
 *
 * A permutation of an array of integers is an arrangement of its members into
 * a sequence or linear order.
 *
 *
 * For example, for arr = [1,2,3], the following are considered permutations of
 * arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
 *
 *
 * The next permutation of an array of integers is the next lexicographically
 * greater permutation of its integer. More formally, if all the permutations
 * of the array are sorted in one container according to their lexicographical
 * order, then the next permutation of that array is the permutation that
 * follows it in the sorted container. If such arrangement is not possible, the
 * array must be rearranged as the lowest possible order (i.e., sorted in
 * ascending order).
 *
 *
 * For example, the next permutation of arr = [1,2,3] is [1,3,2].
 * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 * While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does
 * not have a lexicographical larger rearrangement.
 *
 *
 * Given an array of integers nums, find the next permutation of nums.
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
// 2022-08-01 submission
// 265/265 cases passed
// Runtime: 3 ms, faster than 90.13% of C++ online submissions.
// Memory Usage: 12.1 MB, less than 36.5% of C++ online submissions.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end