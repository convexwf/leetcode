/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
// 2023-01-14 submission
// 15/15 cases passed
// Runtime: 25 ms, faster than 83.56% of C++ online submissions.
// Memory Usage: 17.1 MB, less than 75.04% of C++ online submissions.
class NumArray {
public:
    NumArray(vector<int> &nums) {
        dp.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }

private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end