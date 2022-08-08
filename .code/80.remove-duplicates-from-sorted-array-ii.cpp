/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * algorithms
 * Medium (50.97%)
 * Likes:    3806
 * Dislikes: 934
 * Total Accepted:    446.5K
 * Total Submissions: 876.1K
 * Testcase Example:  '[1,1,1,2,2,3]'
 *
 * Given an integer array nums sorted in non-decreasing order, remove some
 * duplicates in-place such that each unique element appears at most twice. The
 * relative order of the elements should be kept the same.
 * 
 * Since it is impossible to change the length of the array in some languages,
 * you must instead have the result be placed in the first part of the array
 * nums. More formally, if there are k elements after removing the duplicates,
 * then the first k elements of nums should hold the final result. It does not
 * matter what you leave beyond the first k elements.
 * 
 * Return k after placing the final result in the first k slots of nums.
 * 
 * Do not allocate extra space for another array. You must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Custom Judge:
 * 
 * The judge will test your solution with the following code:
 * 
 * 
 * int[] nums = [...]; // Input array
 * int[] expectedNums = [...]; // The expected answer with correct length
 * 
 * int k = removeDuplicates(nums); // Calls your implementation
 * 
 * assert k == expectedNums.length;
 * for (int i = 0; i < k; i++) {
 * ⁠   assert nums[i] == expectedNums[i];
 * }
 * 
 * 
 * If all assertions pass, then your solution will be accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3]
 * Output: 5, nums = [1,1,2,2,3,_]
 * Explanation: Your function should return k = 5, with the first five elements
 * of nums being 1, 1, 2, 2 and 3 respectively.
 * It does not matter what you leave beyond the returned k (hence they are
 * underscores).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,0,1,1,1,1,2,3,3]
 * Output: 7, nums = [0,0,1,1,2,3,3,_,_]
 * Explanation: Your function should return k = 7, with the first seven
 * elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
 * It does not matter what you leave beyond the returned k (hence they are
 * underscores).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 * 
 * 
 */

// @lc code=start
// 2022-08-07 submission
// 164/164 cases passed
// Runtime: 19 ms, faster than 7.02% of C++ online submissions.
// Memory Usage: 10.7 MB, less than 93.05% of C++ online submissions.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                ++cnt;
                if (cnt <= 2) {
                    nums[++pre] = nums[i];
                }
            }
            else {
                cnt = 1;
                nums[++pre] = nums[i];
            }
        }
        return pre + 1;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-07 submission
// 164/164 cases passed
// Runtime: 11 ms, faster than 43.14% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 75.43% of C++ online submissions.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 2 || num > nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
// @lc code=end