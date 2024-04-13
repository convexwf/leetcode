/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
// 1. 前缀和+哈希表
// 2023-06-12 submission
// 98/98 cases passed
// Runtime: 250 ms, faster than 54.64% of cpp online submissions.
// Memory Usage: 113.8 MB, less than 68.32% of cpp online submissions.
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < n; ++i) {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder)) {
                int prevIndex = mp[remainder];
                if (i - prevIndex >= 2) return true; // 子数组长度至少为 2
            }
            else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};
// @lc code=end
