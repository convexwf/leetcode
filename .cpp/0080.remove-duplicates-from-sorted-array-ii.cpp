/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
// 1. 双指针
// 2022-08-07 submission
// 164/164 cases passed
// Runtime: 4 ms, faster than 66.21% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 75.52% of cpp online submissions.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            if (cnt <= 2) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-07 submission
// 164/164 cases passed
// Runtime: 11 ms, faster than 43.14% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 75.43% of cpp online submissions.
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
