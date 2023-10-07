/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// 2022-11-17 submission
// 54/54 cases passed
// Runtime: 714 ms, faster than 30.77% of C++ online submissions.
// Memory Usage: 10.6 MB, less than 50.47% of C++ online submissions.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-18 submission
// 54/54 cases passed
// Runtime: 9 ms, faster than 96.56% of C++ online submissions.
// Memory Usage: 10.4 MB, less than 72.3% of C++ online submissions.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(nums[i]);
            else dp[right] = nums[i];
        }
        return dp.size();
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 54/54 cases passed
// Runtime: 16 ms, faster than 87.99% of C++ online submissions.
// Memory Usage: 10.3 MB, less than 98.38% of C++ online submissions.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(nums[i]);
            else dp[right] = nums[i];
        }
        return dp.size();
    }
};
// @lc code=end