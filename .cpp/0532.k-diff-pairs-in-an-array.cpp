/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
// 1. 哈希表
// 2022-11-15 submission
// 60/60 cases passed
// Runtime: 15 ms, faster than 96.37% of cpp online submissions.
// Memory Usage: 13.2 MB, less than 74.4% of cpp online submissions.
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int res = 0;
        for (auto& [num, cnt] : mp) {
            if ((k == 0 && cnt > 1) || (k != 0 && mp.count(num + k))) {
                res++;
            }
        }

        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 双指针
// 2025-02-21 submission
// 60/60 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 14.9 MB, less than 94.4% of cpp online submissions.
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            j = max(j, i + 1);
            while (j < nums.size() && nums[j] - nums[i] < k) {
                ++j;
            }
            if (j < nums.size() && nums[j] - nums[i] == k) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
