/*
 * @lc app=leetcode id=487 lang=cpp
 *
 * [487] Max Consecutive Ones II
 */

// @lc code=start
// 1. 滑动窗口
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l;
    }
};
// @lc code=end
