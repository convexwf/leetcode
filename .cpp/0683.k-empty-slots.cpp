/*
 * @lc app=leetcode id=683 lang=cpp
 *
 * [683] K Empty Slots
 */

// @lc code=start
// 1. 有序集合
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> s;
        for (int i = 0; i < bulbs.size(); ++i) {
            auto it = s.insert(bulbs[i]).first;
            if (it != s.begin()) {
                if (*it - *prev(it) == k + 1) {
                    return i + 1;
                }
            }
            if (next(it) != s.end()) {
                if (*next(it) - *it == k + 1) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
