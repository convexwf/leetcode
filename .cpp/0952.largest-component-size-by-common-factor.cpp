/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 */

// @lc code=start
// 1. 并查集
// 2025-03-03 submission
// 108/108 cases passed
// Runtime: 232 ms, faster than 26.31% of cpp online submissions.
// Memory Usage: 55.4 MB, less than 83.17% of cpp online submissions.
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);

        for (int num : nums) {
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    parent[find(parent, num)] = find(parent, i);
                    parent[find(parent, num)] = find(parent, num / i);
                }
            }
        }

        unordered_map<int, int> count;
        int res = 0;
        for (int num : nums) {
            res = max(res, ++count[find(parent, num)]);
        }
        return res;
    }
};
// @lc code=end
