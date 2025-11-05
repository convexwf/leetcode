/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
// 1. 前缀和+单调队列
// 2025-06-08 submission
// 98/98 cases passed
// Runtime: 29 ms, faster than 63.72% of cpp online submissions.
// Memory Usage: 109.1 MB, less than 66.59% of cpp online submissions.
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> q;
        int minLength = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            while (!q.empty() && prefix[i] - prefix[q.front()] >= k) {
                minLength = min(minLength, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && prefix[i] <= prefix[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
// @lc code=end
