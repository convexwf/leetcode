/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
// 1. 哈希表
// 2023-11-23 submission
// 103/103 cases passed
// Runtime: 15 ms, faster than 97.5% of cpp online submissions.
// Memory Usage: 25.1 MB, less than 64.2% of cpp online submissions.
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.count(num)) {
                return num;
            }
            s.insert(num);
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 鸽巢原理
// 2023-11-23 submission
// 103/103 cases passed
// Runtime: 27 ms, faster than 65.96% of cpp online submissions.
// Memory Usage: 25.2 MB, less than 51.34% of cpp online submissions.
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
                return nums[i];
            }
        }
        return nums.back();
    }
};
// @lc code=end
