/*
 * @lc app=leetcode id=548 lang=cpp
 *
 * [548] Split Array with Equal Sum
 */

// @lc code=start
// 1. 前缀和数组+哈希表
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) {
            return false;
        }
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> sumSet;
            for (int i = 1; i < j - 1; ++i) {
                if (preSum[i] - preSum[0] == preSum[j] - preSum[i + 1]) {
                    sumSet.insert(preSum[i] - preSum[0]);
                }
            }
            for (int k = j + 2; k < n - 1; ++k) {
                if (preSum[k] - preSum[j + 1] == preSum[n] - preSum[k + 1] && sumSet.count(preSum[k] - preSum[j + 1])) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
