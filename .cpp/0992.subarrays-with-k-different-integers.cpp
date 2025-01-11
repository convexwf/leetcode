/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
// 1. 滑动窗口+哈希表
// 2025-01-06 submission
// 57/57 cases passed
// Runtime: 39 ms, faster than 94.69% of cpp online submissions.
// Memory Usage: 53.4 MB, less than 89.59% of cpp online submissions.
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k - 1);
    }

    int count(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        int num = 0, res = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (counter[nums[i]]++ == 0) {
                ++num;
            }
            while (num > k) {
                if (--counter[nums[j++]] == 0) {
                    --num;
                }
            }
            res += i - j + 1;
        }
        return res;
    }
};
// @lc code=end
