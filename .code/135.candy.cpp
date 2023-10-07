/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
// 2022-07-30 submission
// 48/48 cases passed
// Runtime: 37 ms, faster than 46.94% of C++ online submissions.
// Memory Usage: 17.7 MB, less than 59.74% of C++ online submissions.
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