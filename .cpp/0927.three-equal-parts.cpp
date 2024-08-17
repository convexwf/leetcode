/*
 * @lc app=leetcode id=927 lang=cpp
 *
 * [927] Three Equal Parts
 */

// @lc code=start
// 1. 计数+三指针
// 2023-07-13 submission
// 121/121 cases passed
// Runtime: 50 ms, faster than 59.42% of cpp online submissions.
// Memory Usage: 38.9 MB, less than 84.06% of cpp online submissions.
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n = A.size();
        int ones = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1) ++ones;
        }
        if (ones == 0) return {0, 2};
        if (ones % 3 != 0) return {-1, -1};
        int k = ones / 3;
        int start = 0, mid = 0, end = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1) {
                ++cnt;
                if (cnt == 1) start = i;
                if (cnt == k + 1) mid = i;
                if (cnt == 2 * k + 1) end = i;
            }
        }
        while (end < n && A[start] == A[mid] && A[mid] == A[end]) {
            ++start;
            ++mid;
            ++end;
        }
        if (end == n) return {start - 1, mid};
        return {-1, -1};
    }
};
// @lc code=end
