/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
// 1. 暴力解法
// 2023-05-22 submission
// 52/52 cases passed
// Runtime: 19 ms, faster than 85.4% of cpp online submissions.
// Memory Usage: 17.7 MB, less than 72.05% of cpp online submissions.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        int left = (n - 1) / 2; // [0, 1, 2, 3] 取 1，[0, 1, 2, 3, 4] 取 2
        int right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                nums[i] = tmp[right--];
            }
            else {
                nums[i] = tmp[left--];
            }
        }
    }
};
// @lc code=end
