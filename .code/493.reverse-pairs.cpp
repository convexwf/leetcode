/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (30.90%)
 * Likes:    4493
 * Dislikes: 218
 * Total Accepted:    116.7K
 * Total Submissions: 377.6K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an integer array nums, return the number of reverse pairs in the
 * array.
 *
 * A reverse pair is a pair (i, j) where:
 *
 *
 * 0 <= i < j < nums.length and
 * nums[i] > 2 * nums[j].
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,2,3,1]
 * Output: 2
 * Explanation: The reverse pairs are:
 * (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
 * (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,4,3,5,1]
 * Output: 3
 * Explanation: The reverse pairs are:
 * (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
 * (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
 * (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> vec;

    int reversePairs(vector<int>& nums) {

    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int lp = l, rp = mid + 1, idx = lp;
        while (lp <= mid && rp <= r) {
            if (nums[lp] <= nums[rp]) {
                res += ()
                vec[idx++] = nums[lp++];
            }
            else {
                vec[idx++] = nums[rp++];
            }
        }
        while (lp <= mid) {
            vec[idx++] = nums[lp++];
        }
        while (rp <= r) vec[idx++] = nums[rp++];
        for (int i = l; i <= r; i++) {
            vec[i] = tmp[i - l];
        }
    }
};
// @lc code=end

