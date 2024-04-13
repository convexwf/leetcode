/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */

// @lc code=start
// 1. 哈希表
// 2023-09-15 submission
// 56/56 cases passed
// Runtime: 6 ms, faster than 32.35% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 9.68% of cpp online submissions.
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        int res = 0;
        for (int x : answers) {
            if (m.count(x) && m[x] > 0) {
                m[x]--;
            }
            else {
                m[x] = x;
                res += x + 1;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 数组
// 2023-09-15 submission
// 56/56 cases passed
// Runtime: 6 ms, faster than 32.35% of cpp online submissions.
// Memory Usage:  MB, less than 9.68% of cpp online submissions.
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        vector<int> cnt(1000, 0);
        for (int ans : answers) cnt[ans] = (cnt[ans] + 1) % (ans + 1);
        for (int i = 0; i < 1000; ++i) {
            if (cnt[i] != 0) res += i + 1 - cnt[i];
        }
        return res + answers.size();
    }
};
// @lc code=end
