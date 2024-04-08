/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
// 1. 两次遍历
// 2024-03-01 submission
// 48/48 cases passed
// Runtime: 21 ms, faster than 21.35% of cpp online submissions.
// Memory Usage: 20.5 MB, less than 13.26% of cpp online submissions.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        int res = left[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
            res += max(left[i], right[i]);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 两次遍历+优化
// 2022-07-30 submission
// 48/48 cases passed
// Runtime: 37 ms, faster than 46.94% of cpp online submissions.
// Memory Usage: 17.7 MB, less than 59.74% of cpp online submissions.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, n = ratings.size();
        vector<int> nums(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            if (ratings[i + 1] > ratings[i]) {
                nums[i + 1] = nums[i] + 1;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) {
                nums[i - 1] = max(nums[i - 1], nums[i] + 1);
            }
        }
        for (int num : nums) {
            res += num;
        }
        return res;
    }
};
// @lc code=end
