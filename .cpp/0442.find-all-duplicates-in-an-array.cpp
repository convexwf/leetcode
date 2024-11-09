/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
// 1. 取负法
// 2021-03-19 submission
// 28/28 cases passed
// Runtime: 71 ms, faster than 76.13% of cpp online submissions.
// Memory Usage: 33.6 MB, less than 81.71% of cpp online submissions.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int dst = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            dst = nums[i] > 0 ? nums[i] : nums[i] + (n + 1);
            if (nums[dst - 1] >= 0) {
                nums[dst - 1] -= (n + 1);
            }
            else {
                res.push_back(dst);
            }
        }
        return res;
    }
    // 另一种写法
    // vector<int> findDuplicates(vector<int>& nums) {
    //     vector<int> res;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int idx = abs(nums[i]) - 1;
    //         if (nums[idx] < 0) res.push_back(idx + 1);
    //         nums[idx] = -nums[idx];
    //     }
    //     return res;
    // }
};
// @lc code=end

// @lc code=start
// 2. 替换法
// 2023-01-14 submission
// 28/28 cases passed
// Runtime: 76 ms, faster than 71.78% of cpp online submissions.
// Memory Usage: 33.5 MB, less than 81.71% of cpp online submissions.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
