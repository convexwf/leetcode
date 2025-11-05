/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
// 1. 有序字典
// 2023-09-14 submission
// 84/84 cases passed
// Runtime: 54 ms, faster than 86.18% of cpp online submissions.
// Memory Usage: 28.6 MB, less than 20.85% of cpp online submissions.
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W != 0) return false;
        map<int, int> m;
        for (int i : hand) m[i]++;
        while (!m.empty()) {
            int start = m.begin()->first;
            for (int i = 0; i < W; i++) {
                if (m.find(start + i) == m.end()) return false;
                if (--m[start + i] == 0) m.erase(start + i);
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 有序字典-优化
// 2023-09-14 submission
// 84/84 cases passed
// Runtime: 78 ms, faster than 32.75% of cpp online submissions.
// Memory Usage: 28.6 MB, less than 20.85% of cpp online submissions.
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> m;
        for (int i : hand) ++m[i];
        for (auto a : m) {
            if (a.second == 0) continue;
            for (int i = a.first; i < a.first + W; ++i) {
                if (m[i] < a.second) return false;
                m[i] = m[i] - a.second;
            }
        }
        return true;
    }
};
// @lc code=end
