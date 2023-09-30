/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
// 1. 排序+贪心
// 2023-09-28 submission
// 84/84 cases passed
// Runtime: 23 ms, faster than 90.63% of cpp online submissions.
// Memory Usage: 22.2 MB, less than 15.4% of cpp online submissions.
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = (int)A.size() - 1; i >= 2; --i) {
            if (A[i] < A[i - 1] + A[i - 2]) {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }
        return 0;
    }
};
// @lc code=end
