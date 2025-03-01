/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
// 1. 排序+二分查找
// 2023-02-13 submission
// 241/241 cases passed
// Runtime: 425 ms, faster than 21.84% of cpp online submissions.
// Memory Usage: 13 MB, less than 11.25% of cpp online submissions.
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];
                int left = j + 1, right = n;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) {
                        left = mid + 1;
                    }
                    else {
                        right = mid;
                    }
                }
                res += right - 1 - j;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 排序+双指针
// 2023-02-13 submission
// 241/241 cases passed
// Runtime: 103 ms, faster than 83.01% of cpp online submissions.
// Memory Usage: 13.1 MB, less than 11.25% of cpp online submissions.
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    res += right - left;
                    --right;
                }
                else {
                    ++left;
                }
            }
        }
        return res;
    }
};
// @lc code=end
