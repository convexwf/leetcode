/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
// 1. 滑动窗口
// 2022-11-15 submission
// 307/307 cases passed
// Runtime: 29 ms, faster than 96.69% of cpp online submissions.
// Memory Usage: 26.6 MB, less than 65.27% of cpp online submissions.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i = INT_MAX;
        int max_val = INT_MIN;
        int res = 0;
        for (int j = 1; j < nums.size(); j++) {
            max_val = max(max_val, nums[j - 1]);
            if (nums[j] < max_val) {
                i = min(i, j - 1);
                while (i >= 0 && nums[j] < nums[i]) --i;
                res = max(res, j - i);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 排序+双指针
// 2025-02-24 submission
// 307/307 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 31.7 MB, less than 38.34% of cpp online submissions.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int n = nums.size();
        int start = n, end = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != sorted_nums[i]) {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return end - start >= 0 ? end - start + 1 : 0;
    }
};
// @lc code=end

// @lc code=start
// 3. 双指针
// 2022-11-15 submission
// 307/307 cases passed
// Runtime: 89 ms, faster than 23.17% of cpp online submissions.
// Memory Usage: 26.3 MB, less than 98.49% of cpp online submissions.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n - 1], mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            if (mx > nums[i]) {
                end = i;
            }
            if (mn < nums[n - 1 - i]) {
                start = n - 1 - i;
            }
        }
        return end - start + 1;
    }
};
// @lc code=end
