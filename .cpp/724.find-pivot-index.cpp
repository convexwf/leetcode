/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
// 1. 前缀和
// 2023-08-17 submission
// 746/746 cases passed
// Runtime: 22 ms, faster than 66.98% of cpp online submissions.
// Memory Usage: 31.6 MB, less than 15.97% of cpp online submissions.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (sum[i] == sum[n] - sum[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法
// 2023-08-17 submission
// 746/746 cases passed
// Runtime: 14 ms, faster than 93.91% of cpp online submissions.
// Memory Usage: 31.2 MB, less than 41.88% of cpp online submissions.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (leftSum == sum - nums[i] - leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
// @lc code=end
