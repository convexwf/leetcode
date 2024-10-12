/*
 * @lc app=leetcode id=280 lang=cpp
 *
 * [280] Wiggle Sort
 */

// @lc code=start
// 1. 排序
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) return;
        for (int i = 2; i < nums.size(); i += 2) {
            swap(nums[i], nums[i - 1]);
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 交换
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
// @lc code=end
