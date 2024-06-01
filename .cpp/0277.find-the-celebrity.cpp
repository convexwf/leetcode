/*
 * @lc app=leetcode id=277 lang=cpp
 *
 * [277] Find the Celebrity
 */

// @lc code=start
// 1. 候选数
class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != candidate && (knows(candidate, i) || !knows(i, candidate))) {
                return -1;
            }
        }
        return candidate;
    }
};
// @lc code=end

// @lc code=start
// 2. 候选数-调用次数优化
class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        for (int i = 0; i < candidate; ++i) {
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }
        for (int i = candidate + 1; i < n; ++i) {
            if (!knows(i, candidate)) {
                return -1;
            }
        }
        return candidate;
    }
};
// @lc code=end
