/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start
// 1. 位运算
// 2024-01-25 submission
// 80/80 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 10.56% of cpp online submissions.
class Solution {
public:
    int press(int state, int button) {
        switch (button) {
            case 1:
                return ~state;
            case 2:
                return state ^ 0b101010;
            case 3:
                return state ^ 0b010101;
            case 4:
                return state ^ 0b001001;
        }
        return state;
    }

    int flipLights(int n, int presses) {
        n = min(n, 6);
        if (presses > 2) {
            presses = 4 - presses % 2;
        }
        int mask = (1 << n) - 1;
        queue<char> q;
        unordered_set<char> seen;
        q.push(0b111111 & mask);
        seen.insert(0b111111 & mask);
        while (!q.empty() && presses-- > 0) {
            int qsize = q.size();
            seen.clear();
            while (qsize-- > 0) {
                int state = q.front();
                q.pop();
                for (int i = 1; i <= 4; ++i) {
                    int next = press(state, i) & mask;
                    if (!seen.count(next)) {
                        q.push(next);
                        seen.insert(next);
                    }
                }
            }
        }
        return seen.size();
    }
};
// @lc code=end

// @lc code=start
// 2. 打表法
// 2024-01-25 submission
// 80/80 cases passed
// Runtime: 3 ms, faster than 26.76% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 17.61% of cpp online submissions.
class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses == 0) {
            return 1;
        }
        if (n == 1) {
            return 2;
        }
        if (n == 2) {
            return presses == 1 ? 3 : 4;
        }
        if (presses == 1) {
            return 4;
        }
        return presses == 2 ? 7 : 8;
    }
};
// @lc code=end
