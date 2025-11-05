/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
// 1. 滑动窗口
// 2020-11-04 submission
// 20/20 cases passed
// Runtime: 38 ms, faster than 88.21% of cpp online submissions.
// Memory Usage: 28.3 MB, less than 12.43% of cpp online submissions.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l_pivot = 0;
        int res = INT_MAX;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            while (cur >= s) {
                res = min(res, i - l_pivot + 1);
                cur -= nums[l_pivot];
                ++l_pivot;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找
// 2020-11-04 submission
// 20/20 cases passed
// Runtime: 45 ms, faster than 68.19% of cpp online submissions.
// Memory Usage: 29 MB, less than 8.36% of cpp online submissions.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n, t = sums[i] + s;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sums[mid] < t) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if (left == n + 1) break;
            res = min(res, left - i);
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
