/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
// 1. 前缀和数组
// 2023-01-14 submission
// 15/15 cases passed
// Runtime: 25 ms, faster than 83.56% of cpp online submissions.
// Memory Usage: 17.1 MB, less than 75.04% of cpp online submissions.
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
