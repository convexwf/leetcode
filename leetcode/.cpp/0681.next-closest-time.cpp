/*
 * @lc app=leetcode id=681 lang=cpp
 *
 * [681] Next Closest Time
 */

// @lc code=start
// 1. 枚举时刻
class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> s;
        for (int i = 0; i < 5; i++) {
            if (i == 2) continue;
            s.insert(time[i] - '0');
        }
        int cur = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
        while (true) {
            cur = (cur + 1) % 1440;
            int h1 = cur / 60 / 10, h2 = cur / 60 % 10, m1 = cur % 60 / 10, m2 = cur % 60 % 10;
            if (s.count(h1) && s.count(h2) && s.count(m1) && s.count(m2)) {
                return to_string(h1) + to_string(h2) + ":" + to_string(m1) + to_string(m2);
            }
        }
        return "";
    }
};
// @lc code=end
