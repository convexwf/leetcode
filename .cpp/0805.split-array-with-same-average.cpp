/*
 * @lc app=leetcode id=805 lang=cpp
 *
 * [805] Split Array With Same Average
 */

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int m = n / 2;
        for (int i = 1; i <= m; ++i) {
            if (s * i % n == 0) {
                if (dfs(nums, s * i / n, i, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<int>& nums, int target, int k, int start) {
        if (k == 0) {
            return target == 0;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (dfs(nums, target - nums[i], k - 1, i + 1)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
