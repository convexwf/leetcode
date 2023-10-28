/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// @lc code=start
// 1. 数组遍历
// 2023-10-27 submission
// 66/66 cases passed
// Runtime: 123 ms, faster than 50.66% of cpp online submissions.
// Memory Usage: 98.6 MB, less than 47.26% of cpp online submissions.
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMin(n);
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        int leftMax = nums[0];
        for (int i = 0; i < n - 1; ++i) {
            leftMax = max(leftMax, nums[i]);
            if (leftMax <= rightMin[i + 1]) {
                return i + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

// @lc code=start
// 2. 数组遍历优化
// 2023-10-27 submission
// 66/66 cases passed
// Runtime: 119 ms, faster than 65.79% of cpp online submissions.
// Memory Usage: 94.5 MB, less than 93.28% of cpp online submissions.
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int partitionIdx = 0, preMax = A[0], curMax = preMax;
        for (int i = 1; i < A.size(); ++i) {
            curMax = max(curMax, A[i]);
            if (A[i] < preMax) {
                preMax = curMax;
                partitionIdx = i;
            }
        }
        return partitionIdx + 1;
    }
};
// @lc code=end
