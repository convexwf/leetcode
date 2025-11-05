/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
// 1. 贪心算法
// 2023-02-22 submission
// 52/52 cases passed
// Runtime: 4 ms, faster than 29.59% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 81.12% of cpp online submissions.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        int max_val = 0;
        for (int i = 0; i < n; i++) {
            max_val = max(max_val, arr[i]);
            if (max_val == i) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
