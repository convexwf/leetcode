/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
// 1. 哈希集合
// 2020-09-16 submission
// 72/72 cases passed
// Runtime: 153 ms, faster than 79.42% of cpp online submissions.
// Memory Usage: 45.7 MB, less than 78.51% of cpp online submissions.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            if (!s.count(num)) continue;
            s.erase(num);
            int pre = num - 1, next = num + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表
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
            int left = m[num - 1];
            int right = m[num + 1];
            int sum = left + right + 1;
            m[num] = sum;
            m[num - left] = sum;
            m[num + right] = sum;
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 排序
// 2024-07-03 submission
// 76/76 cases passed
// Runtime: 60 ms, faster than 95.16% of cpp online submissions.
// Memory Usage: 49.5 MB, less than 78.86% of cpp online submissions.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 1, cur = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    ++cur;
                }
                else {
                    res = max(res, cur);
                    cur = 1;
                }
            }
        }
        return max(res, cur);
    }
};
// @lc code=end
