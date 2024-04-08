/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
// 2022-08-19 submission
// 206/206 cases passed
// Runtime: 206 ms, faster than 19.15% of cpp online submissions.
// Memory Usage: 41.6 MB, less than 35.24% of cpp online submissions.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto it = next(m.begin()); it != m.end(); ++it) {
            auto pre = prev(it);
            if (it->first == pre->first + 1) {
                res = max(res, it->second + pre->second);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 206/206 cases passed
// Runtime: 95 ms, faster than 85.98% of cpp online submissions.
// Memory Usage: 40.1 MB, less than 52.71% of cpp online submissions.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto a : m) {
            if (m.count(a.first + 1)) {
                res = max(res, m[a.first] + m[a.first + 1]);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 206/206 cases passed
// Runtime: 162 ms, faster than 36.92% of cpp online submissions.
// Memory Usage: 39.9 MB, less than 72.75% of cpp online submissions.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            ++m[num];
            if (m.count(num + 1)) {
                res = max(res, m[num] + m[num + 1]);
            }
            if (m.count(num - 1)) {
                res = max(res, m[num] + m[num - 1]);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 206/206 cases passed
// Runtime: 73 ms, faster than 97.04% of cpp online submissions.
// Memory Usage: 32.5 MB, less than 89.93% of cpp online submissions.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        for (int r = 1; r < nums.size(); ++r) {
            if (nums[r] - nums[l] == 1) {
                res = max(res, r - l + 1);
            }
            else if (nums[r] - nums[l] > 1) {
                while (nums[r] - nums[l] > 1) ++l;
            }
        }
        return res;
    }
};
// @lc code=end
