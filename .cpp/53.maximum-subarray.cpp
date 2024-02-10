/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
// 2022-07-20 submission
// 209/209 cases passed
// Runtime: 167 ms, faster than 49.74% of C++ online submissions.
// Memory Usage: 67.8 MB, less than 10.9% of C++ online submissions.
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
// 2022-07-20 submission
// 209/209 cases passed
// Runtime: 273 ms, faster than 5.09% of C++ online submissions.
// Memory Usage: 67.8 MB, less than 53.44% of C++ online submissions.
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return helper(nums, 0, (int)nums.size() - 1);
    }

    int helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = helper(nums, left, mid - 1);
        int rmax = helper(nums, mid + 1, right);
        int mmax = nums[mid], t = mmax;
        for (int i = mid - 1; i >= left; --i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for (int i = mid + 1; i <= right; ++i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(lmax, rmax));
    }
};
// @lc code=end