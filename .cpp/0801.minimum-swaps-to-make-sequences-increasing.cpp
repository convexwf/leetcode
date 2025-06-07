/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */

// @lc code=start
// 1. 动态规划
// 2025-06-06 submission
// 117/117 cases passed
// Runtime: 3 ms, faster than 91.8% of cpp online submissions.
// Memory Usage: 98.3 MB, less than 72.64% of cpp online submissions.
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> noswap(n, n), swap(n, n);
        noswap[0] = 0;
        swap[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                // if both sequences are already increasing
                noswap[i] = noswap[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                // if we can swap to make both sequences increasing
                noswap[i] = min(noswap[i], swap[i - 1]);
                swap[i] = min(swap[i], noswap[i - 1] + 1);
            }
        }
        return min(noswap[n - 1], swap[n - 1]);
    }
};
// @lc code=end
