/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
// 2023-01-14 submission
// 58/58 cases passed
// Runtime: 1081 ms, faster than 29.17% of C++ online submissions.
// Memory Usage: 89.6 MB, less than 29.71% of C++ online submissions.
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    bool canWin(int length, int total, int used, unordered_map<int, bool>& m) {
        if (m.count(used)) return m[used];
        for (int i = 0; i < length; ++i) {
            int cur = (1 << i);
            if ((cur & used) == 0) {
                if (total <= i + 1 || !canWin(length, total - (i + 1), cur | used, m)) {
                    m[used] = true;
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
};
// @lc code=end