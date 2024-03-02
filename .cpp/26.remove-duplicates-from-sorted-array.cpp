/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
// 1. 双指针
// 2022-07-28 submission
// 361/361 cases passed
// Runtime: 16 ms, faster than 66.6% of C++ online submissions.
// Memory Usage: 18.1 MB, less than 99.74% of C++ online submissions.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[pre]) {
                nums[++pre] = nums[i];
            }
        }
        return pre + 1;
    }
};
// @lc code=end
