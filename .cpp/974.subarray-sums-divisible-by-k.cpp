/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
// 1. 前缀和+哈希表
// 2023-10-10 submission
// 73/73 cases passed
// Runtime: 45 ms, faster than 50.33% of cpp online submissions.
// Memory Usage: 31.9 MB, less than 34.19% of cpp online submissions.
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, ans = 0;
        for (int num : nums) {
            sum += num;
            // 保证 mod >= 0
            int mod = (sum % k + k) % k;
            if (m.count(mod)) {
                ans += m[mod];
            }
            m[mod]++;
        }
        return ans;
    }
};
// @lc code=end
