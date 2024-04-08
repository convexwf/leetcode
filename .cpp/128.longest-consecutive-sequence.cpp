/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
// 2020-09-16 submission
// 72/72 cases passed
// Runtime: 153 ms, faster than 79.42% of cpp online submissions.
// Memory Usage: 45.7 MB, less than 78.51% of cpp online submissions.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> hash_set(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (!hash_set.count(nums[i])) continue;
            hash_set.erase(nums[i]);
            int pre = nums[i], next = nums[i];
            while (hash_set.count(--pre)) hash_set.erase(pre);
            while (hash_set.count(++next)) hash_set.erase(next);
            max_len = max(max_len, next - pre - 1);
        }
        return max_len;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 72/72 cases passed
// Runtime: 166 ms, faster than 76.2% of cpp online submissions.
// Memory Usage: 49.8 MB, less than 58.47% of cpp online submissions.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            if (m.count(num)) continue;
            int left = m.count(num - 1) ? m[num - 1] : 0;
            int right = m.count(num + 1) ? m[num + 1] : 0;
            int sum = left + right + 1;
            m[num] = sum;
            res = max(res, sum);
            m[num - left] = sum;
            m[num + right] = sum;
        }
        return res;
    }
};
// @lc code=end
