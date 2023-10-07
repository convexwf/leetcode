/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
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

