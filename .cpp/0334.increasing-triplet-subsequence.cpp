/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
// 1. 标记变量
// 2023-02-13 submission
// 78/78 cases passed
// Runtime: 150 ms, faster than 49.78% of cpp online submissions.
// Memory Usage: 111.7 MB, less than 19.22% of cpp online submissions.
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (auto a : nums) {
            if (m1 >= a) {
                m1 = a;
            }
            else if (m2 >= a) {
                m2 = a;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 最大值和最小值数组
// 2023-02-13 submission
// 78/78 cases passed
// Runtime: 178 ms, faster than 20.57% of cpp online submissions.
// Memory Usage: 121.1 MB, less than 5.53% of cpp online submissions.
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int n = nums.size();
        vector<int> f(n, nums[0]), b(n, nums.back());
        for (int i = 1; i < n; ++i) {
            f[i] = min(f[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            b[i] = max(b[i + 1], nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > f[i] && nums[i] < b[i]) return true;
        }
        return false;
    }
};
// @lc code=end
