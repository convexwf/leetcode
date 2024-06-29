/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
// 1. 哈希表
// 2021-12-15 submission
// 89/89 cases passed
// Runtime: 44 ms, faster than 56.21% of cpp online submissions.
// Memory Usage: 25.5 MB, less than 67.47% of cpp online submissions.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;     // 出现次数的映射
        unordered_map<int, int> right; // 右边界的映射
        int max_val = 0;               // 数组的度, 最多出现次数
        for (int i = 0; i < nums.size(); i++) {
            ++m[nums[i]];
            right[nums[i]] = i;
            max_val = max(max_val, m[nums[i]]);
        }

        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] == max_val) {
                res = min(res, right[nums[i]] - i + 1);
                --m[nums[i]];
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+一次遍历
// 2022-08-20 submission
// 89/89 cases passed
// Runtime: 51 ms, faster than 81.98% of cpp online submissions.
// Memory Usage: 25.5 MB, less than 68.97% of cpp online submissions.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;    // 出现次数的映射
        unordered_map<int, int> left; // 左边界的映射
        int max_val = 0;              // 数组的度, 最多出现次数
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (!left.count(nums[i])) {
                left[nums[i]] = i;
            }
            ++m[nums[i]];
            if (m[nums[i]] > max_val) { // 更新数组度，需要重新计算 res
                max_val = m[nums[i]];
                res = nums.size();
            }
            if (m[nums[i]] == max_val) {
                res = min(res, i - left[nums[i]] + 1);
            }
        }
        return res;
    }
};
// @lc code=end
