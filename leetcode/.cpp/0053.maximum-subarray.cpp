/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
// 1. 动态规划
// 2022-07-20 submission
// 209/209 cases passed
// Runtime: 167 ms, faster than 49.74% of cpp online submissions.
// Memory Usage: 67.8 MB, less than 10.9% of cpp online submissions.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int num : nums) {
            // if(currSum >= 0) currSum += num;
            // else currSum = num;
            currSum = max(currSum + num, num);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};
// @lc code=end

// @lc code=start
// 2. 分治法
// 2022-07-20 submission
// 209/209 cases passed
// Runtime: 273 ms, faster than 5.09% of cpp online submissions.
// Memory Usage: 67.8 MB, less than 53.44% of cpp online submissions.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }

    int maxSubArray(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;
        int leftMax = maxSubArray(nums, left, mid);
        int rightMax = maxSubArray(nums, mid + 1, right);

        int leftSum = INT_MIN, rightSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return max(max(leftMax, rightMax), leftSum + rightSum);
    }
};
// @lc code=end
