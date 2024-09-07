/*
 * @lc app=leetcode id=644 lang=cpp
 *
 * [644] Maximum Average Subarray II
 */

// @lc code=start
// 1. 二分查找
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double mid = left + (right - left) / 2;
            if (check(nums, k, mid)) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

    bool check(vector<int>& nums, int k, double mid) {
        int n = nums.size();
        vector<double> sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + (nums[i - 1] - mid);
        }
        double min_sum = 0;
        for (int i = k; i <= n; ++i) {
            if (sum[i] - min_sum >= 0) {
                return true;
            }
            min_sum = min(min_sum, sum[i - k + 1]);
        }
        return false;
    }
};
// @lc code=end
