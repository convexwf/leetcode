/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
// 1. 数组遍历
// 2023-06-13 submission
// 15/15 cases passed
// Runtime: 36 ms, faster than 18.83% of cpp online submissions.
// Memory Usage: 22.3 MB, less than 39.02% of cpp online submissions.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i += 2) {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作
// 2023-06-13 submission
// 15/15 cases passed
// Runtime: 28 ms, faster than 69.14% of cpp online submissions.
// Memory Usage: 22.3 MB, less than 39.02% of cpp online submissions.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 二分查找
// 2023-06-13 submission
// 15/15 cases passed
// Runtime: 29 ms, faster than 58.48% of cpp online submissions.
// Memory Usage: 22.4 MB, less than 39.02% of cpp online submissions.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 1) mid--; // 保证left、right、mid都是偶数
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};
// @lc code=end
