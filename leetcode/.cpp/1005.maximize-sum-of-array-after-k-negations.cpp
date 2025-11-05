/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
// 1. 排序
// 2023-09-25 submission
// 82/82 cases passed
// Runtime: 7 ms, faster than 100% of cpp online submissions.
// Memory Usage: 9.4 MB, less than 17.19% of cpp online submissions.
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int res = 0, n = A.size(), mn = INT_MAX;
        sort(A.begin(), A.end());
        for (int i = 0; i < n && K > 0 && A[i] < 0; ++i, --K) {
            A[i] = -A[i];
        }
        for (int num : A) {
            res += num;
            mn = min(mn, num);
        }
        return res - (K % 2) * 2 * mn;
    }
};
// @lc code=end
