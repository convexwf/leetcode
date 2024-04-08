/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
// 1. 排序+双指针
// 2022-07-18 submission
// 313/313 cases passed
// Runtime: 46 ms, faster than 98.02% of cpp online submissions.
// Memory Usage: 27.1 MB, less than 78.71% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break;                        // 剪枝优化
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 固定数去重
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left; // 双指针数去重
                    while (left < right && nums[right] == nums[right - 1]) --right; // 双指针数去重
                    ++left;
                    --right;
                }
                else if (nums[left] + nums[right] < target) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-18 submission
// 311/311 cases passed
// Runtime: 106 ms, faster than 77.65% of cpp online submissions.
// Memory Usage: 19.9 MB, less than 95.74% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 0) return res;
        sort(nums.begin(), nums.end());
        int l_val = 0, r_val = 0, sum = 0;
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int l = i + 1, r = (int)nums.size() - 1; l < r;) {
                l_val = nums[l];
                r_val = nums[r];
                sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) res.push_back({nums[i], nums[l], nums[r]});
                if (sum >= 0)
                    while (l < r && nums[--r] == r_val)
                        ;
                if (sum <= 0)
                    while (l < r && nums[++l] == l_val)
                        ;
            }
        }
        return res;
    }
};
// @lc code=end
