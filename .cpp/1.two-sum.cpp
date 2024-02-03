/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
// 1. 暴力枚举
// 2024-01-31 submission
// 63/63 cases passed
// Runtime: 45 ms, faster than 48.1% of cpp online submissions.
// Memory Usage: 12.7 MB, less than 15.79% of cpp online submissions.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
// @lc code=end

// @lc code=start
// 2. 排序+双指针
// 2024-01-31 submission
// 63/63 cases passed
// Runtime: 4 ms, faster than 95.57% of cpp online submissions.
// Memory Usage:  MB, less than 10.98% of cpp online submissions.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&nums](int a, int b) { return nums[a] < nums[b]; });
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[index[i]] + nums[index[j]];
            if (sum == target) {
                return {index[i], index[j]};
            }
            else if (sum < target) {
                ++i;
            }
            else {
                --j;
            }
        }
        return {};
    }
};
// @lc code=end

// @lc code=start
// 3. 哈希表
// 2022-05-30 submission
// 57/57 cases passed
// Runtime: 12 ms, faster than 83.93% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 29.71% of C++ online submissions.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            if (m.count(complement)) {
                return {m[complement], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
