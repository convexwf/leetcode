/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
// 1. 滑动窗口
// 2023-09-04 submission
// 55/55 cases passed
// Runtime: 51 ms, faster than 57.1% of cpp online submissions.
// Memory Usage: 55.5 MB, less than 56.01% of cpp online submissions.
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int zero = 0;
        int ans = 0;
        while (right < n) {
            if (nums[right] == 0) {
                zero++;
            }
            while (zero > k) {
                if (nums[left] == 0) {
                    zero--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 滑动窗口优化
// 2023-09-04 submission
// 55/55 cases passed
// Runtime: 36 ms, faster than 95.71% of cpp online submissions.
// Memory Usage: 55.6 MB, less than 21.87% of cpp online submissions.
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        for (; r < n; ++r) {
            if (nums[r] == 0) {
                --k;
            }
            if (k < 0 && nums[l++] == 0) {
                ++k;
            }
        }
        return r - l;
    }
};
// @lc code=end
