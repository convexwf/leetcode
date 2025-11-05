/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
// 1. 栈
// 2023-09-26 submission
// 275/275 cases passed
// Runtime: 8 ms, faster than 77.74% of cpp online submissions.
// Memory Usage: 18.2 MB, less than 9.96% of cpp online submissions.
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (s.empty()) {
                s.push(asteroids[i]);
            }
            else {
                if (s.top() > 0 && asteroids[i] < 0) {
                    if (abs(s.top()) > abs(asteroids[i])) {
                        continue;
                    }
                    else if (abs(s.top()) < abs(asteroids[i])) {
                        s.pop();
                        --i;
                    }
                    else {
                        s.pop();
                    }
                }
                else {
                    s.push(asteroids[i]);
                }
            }
        }
        vector<int> res(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
// @lc code=end
