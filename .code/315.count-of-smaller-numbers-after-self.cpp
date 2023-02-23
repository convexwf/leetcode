/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (42.70%)
 * Likes:    7797
 * Dislikes: 212
 * Total Accepted:    285.2K
 * Total Submissions: 667.8K
 * Testcase Example:  '[5,2,6,1]'
 *
 * Given an integer array nums, return an integer array counts where counts[i]
 * is the number of smaller elements to the right of nums[i].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [-1,-1]
 * Output: [0,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> vec;

    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vec.resize(n);
        return mergeSort(nums, 0, n - 1);
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        int res = 0;
        res += mergeSort(nums, l, mid);
        res += mergeSort(nums, mid + 1, r);
        int lp = l, rp = mid + 1, idx = lp;
        while (lp <= mid && rp <= r) {
            if (nums[lp] <= nums[rp]) {
                res += (rp - 1 - mid);
                vec[idx++] = nums[lp++];
            }
            else {
                vec[idx++] = nums[rp++];
            }
        }
        while (lp <= mid) {
            res += (rp - 1 - mid);
            vec[idx++] = nums[lp++];
        }
        while (rp <= r) vec[idx++] = nums[rp++];
        for (int i = l; i <= r; i++) {
            vec[i] = tmp[i - l];
        }
        return res;
    }
};
// @lc code=end

