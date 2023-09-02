/*
 * @lc app=leetcode id=910 lang=cpp
 *
 * [910] Smallest Range II
 */

// @lc code=start
// 1. 排序
// 2023-09-01 submission
// 69/69 cases passed
// Runtime: 22 ms, faster than 36.93% of cpp online submissions.
// Memory Usage: 15.5 MB, less than 11.4% of cpp online submissions.
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int res = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; ++i) {
            int high = max(A[i] + K, A[n - 1] - K);
            int low = min(A[0] + K, A[i + 1] - K);
            res = min(res, high - low);
        }
        return res;
    }
};
// @lc code=end
