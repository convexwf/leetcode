/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
 */

// @lc code=start
// 1. 哈希表
// 2023-07-03 submission
// 75/75 cases passed
// Runtime: 98 ms, faster than 81.71% of cpp online submissions.
// Memory Usage: 46.9 MB, less than 64.63% of cpp online submissions.
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumB - sumA) / 2;
        unordered_set<int> rec(B.begin(), B.end());
        vector<int> ans;
        for (auto& x : A) {
            int y = x + delta;
            if (rec.count(y)) {
                ans = vector<int>{x, y};
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
