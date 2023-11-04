/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
// 1. 水塘抽样
// 2023-11-01 submission
// 15/15 cases passed
// Runtime: 1982 ms, faster than 5.96% of cpp online submissions.
// Memory Usage: 43.7 MB, less than 88.18% of cpp online submissions.
class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int count = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++count;
                int x = 1 + rand() % count;
                if (count == x) ans = i;
            }
        }
        return ans;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

// @lc code=start
// 2. 哈希表
// 2023-11-01 submission
// 15/15 cases passed
// Runtime: 206 ms, faster than 32.26% of cpp online submissions.
// Memory Usage: 359.2 MB, less than 8.07% of cpp online submissions.
class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = vector<int>();
            }
            m[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        vector<int> v = m[target];
        return v[rand() % v.size()];
    }

private:
    unordered_map<int, vector<int>> m;
};
// @lc code=end
