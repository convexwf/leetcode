/*
 * @lc app=leetcode id=970 lang=cpp
 *
 * [970] Powerful Integers
 */

// @lc code=start
// 1. 模拟
// 2023-09-28 submission
// 104/104 cases passed
// Runtime: 3 ms, faster than 47.98% of cpp online submissions.
// Memory Usage: 6.9 MB, less than 36.32% of cpp online submissions.
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> res;
        for (int i = 1; i < bound; i *= x) {
            for (int j = 1; i + j <= bound; j *= y) {
                res.insert(i + j);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end
