/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
// 1. 前缀和+哈希表
// 2023-06-12 submission
// 564/564 cases passed
// Runtime: 147 ms, faster than 62.92% of cpp online submissions.
// Memory Usage: 83.7 MB, less than 67.94% of cpp online submissions.
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (mp.count(sum)) {
                ans = max(ans, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表
// 2023-06-12 submission
// 564/564 cases passed
// Runtime: 139 ms, faster than 79.55% of cpp online submissions.
// Memory Usage: 83.3 MB, less than 98.44% of cpp online submissions.
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m{{0, -1}}; // 0 的位置为 -1，方便计算长度
        int count = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += (nums[i] == 1) ? 1 : -1;
            if (m.count(count)) {
                res = max(res, i - m[count]);
            }
            else {
                m[count] = i;
            }
        }
        return res;
    }
};
// @lc code=end