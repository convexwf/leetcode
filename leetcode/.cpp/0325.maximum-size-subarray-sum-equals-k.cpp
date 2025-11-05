/*
 * @lc app=leetcode id=325 lang=cpp
 *
 * [325] Maximum Size Subarray Sum Equals k
 */

// @lc code=start
// 1. 前缀和+哈希表
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int preSum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            preSum += nums[i];
            if (preSum == k) {
                maxLen = i + 1;
            }
            else if (map.count(preSum - k)) {
                maxLen = max(maxLen, i - map[preSum - k]);
            }
            if (!map.count(preSum)) {
                map[preSum] = i;
            }
        }
        return maxLen;
    }
};
// @lc code=end
