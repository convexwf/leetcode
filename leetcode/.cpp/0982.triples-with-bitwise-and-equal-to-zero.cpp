/*
 * @lc app=leetcode id=982 lang=cpp
 *
 * [982] Triples with Bitwise AND Equal To Zero
 */

// @lc code=start
// 1. 哈希表
// 2023-07-21 submission
// 25/25 cases passed
// Runtime: 407 ms, faster than 73.82% of cpp online submissions.
// Memory Usage: 12.8 MB, less than 45.55% of cpp online submissions.
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                ++cnt[nums[i] & nums[j]];
            }
        }
        int ans = 0;
        for (auto& [k, v] : cnt) {
            for (int i = 0; i < nums.size(); ++i) {
                if ((nums[i] & k) == 0) {
                    ans += v;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
