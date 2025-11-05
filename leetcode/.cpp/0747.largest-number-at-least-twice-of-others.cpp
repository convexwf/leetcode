/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
// 1. 数组遍历
// 2023-08-28 submission
// 231/231 cases passed
// Runtime: 3 ms, faster than 62.69% of cpp online submissions.
// Memory Usage: 10.8 MB, less than 83.47% of cpp online submissions.
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != maxIndex && nums[maxIndex] < nums[i] * 2) {
                return -1;
            }
        }
        return maxIndex;
    }
};
// @lc code=end

// @lc code=start
// 2. 数组遍历+优化
// 2023-08-28 submission
// 231/231 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 7.97% of cpp online submissions.
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        int maxNum = nums[0];
        int secondMaxNum = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > maxNum) {
                secondMaxNum = maxNum;
                maxNum = nums[i];
                maxIndex = i;
            }
            else if (nums[i] > secondMaxNum) {
                secondMaxNum = nums[i];
            }
        }
        return maxNum >= 2 * secondMaxNum ? maxIndex : -1;
    }
};
// @lc code=end
