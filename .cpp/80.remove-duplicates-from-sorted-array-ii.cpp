/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
// 2022-08-07 submission
// 164/164 cases passed
// Runtime: 19 ms, faster than 7.02% of cpp online submissions.
// Memory Usage: 10.7 MB, less than 93.05% of cpp online submissions.
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
