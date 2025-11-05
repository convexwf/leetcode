/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */

// @lc code=start
// 1. 区间计数
// 2023-12-26 submission
// 46/46 cases passed
// Runtime: 58 ms, faster than 28.89% of cpp online submissions.
// Memory Usage: 52.7 MB, less than 44.24% of cpp online submissions.
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

    int count(vector<int>& nums, int x) {
        int res = 0, count = 0;
        for (int num : nums) {
            count = num > x ? 0 : count + 1;
            res += count;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 滑动窗口
// 2023-12-26 submission
// 46/46 cases passed
// Runtime: 57 ms, faster than 32.36% of cpp online submissions.
// Memory Usage: 52.5 MB, less than 97.44% of cpp online submissions.
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        int res = 0, left = -1, right = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > R) {
                left = right = i;
                continue;
            }
            if (nums[i] >= L) right = i;
            res += right - left;
        }
        return res;
    }
};
// @lc code=end
