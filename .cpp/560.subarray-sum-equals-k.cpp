/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
// 2021-03-17 submission
// 93/93 cases passed
// Runtime: 111 ms, faster than 51.29% of C++ online submissions.
// Memory Usage: 47.5 MB, less than 10.82% of C++ online submissions.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dp{{0 ,1}};
        int sum = 0, res = 0;
        for (int num : nums) {
            sum += num;
            res += dp[sum - k];
            ++dp[sum];
        }
        return res;
    }
};
// @lc code=end
