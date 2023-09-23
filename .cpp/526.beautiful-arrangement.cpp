/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
// 1. 递归
// 2023-09-18 submission
// 15/15 cases passed
// Runtime: 7 ms, faster than 89.72% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 24.18% of cpp online submissions.
class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) nums[i] = i + 1;
        return helper(N, nums);
    }

private:
    int helper(int n, vector<int>& nums) {
        if (n <= 0) return 1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (n % nums[i] == 0 || nums[i] % n == 0) {
                swap(nums[i], nums[n - 1]);
                res += helper(n - 1, nums);
                swap(nums[i], nums[n - 1]);
            }
        }
        return res;
    }
};
// 上面的解法在 N=4 时产生的优美序列如下：
// 2 4 3 1
// 4 2 3 1
// 3 4 1 2
// 4 1 3 2
// 1 4 3 2
// 3 2 1 4
// 2 1 3 4
// 1 2 3 4
// @lc code=end
