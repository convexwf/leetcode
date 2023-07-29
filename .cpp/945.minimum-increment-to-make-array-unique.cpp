/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
// 1. 排序+贪心
// 2023-07-26 submission
// 63/63 cases passed
// Runtime: 176 ms, faster than 94.49% of cpp online submissions.
// Memory Usage: 65.6 MB, less than 85.71% of cpp online submissions.
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int need = nums[0] + 1;
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= need) {
                need = nums[i] + 1;
            }
            else {
                res += need - nums[i];
                need += 1;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        int need = 0, res = 0;
        for (auto& [num, count] : m) {
            res += max(need - num, 0) * count + count * (count - 1) / 2;
            need = max(need, num) + count;
        }
        return res;
    }
};
// @lc code=end
