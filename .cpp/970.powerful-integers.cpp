/*
 * @lc app=leetcode id=970 lang=cpp
 *
 * [970] Powerful Integers
 */

// @lc code=start
// 1. brute force
// 2023-09-28 submission
// 104/104 cases passed
// Runtime: 3 ms, faster than 47.98% of cpp online submissions.
// Memory Usage: 6.9 MB, less than 36.32% of cpp online submissions.
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        for (int a = 1; a < bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                s.insert(a + b);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
// @lc code=end
