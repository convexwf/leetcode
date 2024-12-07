/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
// 1. 哈希表
// 2020-12-18 submission
// 132/132 cases passed
// Runtime: 304 ms, faster than 70.29% of cpp online submissions.
// Memory Usage: 24.2 MB, less than 95.67% of cpp online submissions.
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                mp[nums1[i] + nums2[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < nums3.size(); ++i) {
            for (int j = 0; j < nums4.size(); ++j) {
                if (mp.count(-nums3[i] - nums4[j])) {
                    res += mp[-nums3[i] - nums4[j]];
                }
            }
        }
        return res;
    }
};
// @lc code=end
