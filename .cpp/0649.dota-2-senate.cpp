/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
// 1. 贪心算法+队列
// 2023-08-31 submission
// 82/82 cases passed
// Runtime: 9 ms, faster than 43.52% of cpp online submissions.
// Memory Usage: 8.1 MB, less than 14.81% of cpp online submissions.
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            if (radiant.front() < dire.front())
                radiant.push(radiant.front() + n);
            else
                dire.push(dire.front() + n);
            radiant.pop();
            dire.pop();
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
// @lc code=end
