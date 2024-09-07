/*
 * @lc app=leetcode id=666 lang=cpp
 *
 * [666] Path Sum IV
 */

// @lc code=start
// 1. 哈希表
class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num / 10] = num % 10;
        }
        return dfs(m, nums[0] / 10, 0);
    }

    int dfs(unordered_map<int, int>& m, int num, int sum) {
        if (!m.count(num)) {
            return 0;
        }
        int d = num / 10, p = num % 10;
        int left = (d + 1) * 10 + 2 * p - 1;
        int right = (d + 1) * 10 + 2 * p;
        if (!m.count(left) && !m.count(right)) {
            return sum + m[num];
        }
        return dfs(m, left, sum + m[num]) + dfs(m, right, sum + m[num]);
    }
};
// @lc code=end
