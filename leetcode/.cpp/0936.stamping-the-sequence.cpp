/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 */

// @lc code=start
// 1. 逆向思维+贪心算法
// 2025-02-11 submission
// 262/262 cases passed
// Runtime: 23 ms, faster than 45.41% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 98.98% of cpp online submissions.
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> res;
        int done = 0;
        bool replaced = true;
        while (replaced) {
            replaced = false;
            for (int vsize = m; vsize >= 1; --vsize) {
                for (int i = 0; i + vsize <= n; ++i) {
                    int j = 0, count = 0;
                    while (j < m && (target[i + j] == '?' || target[i + j] == stamp[j])) {
                        if (target[i + j] != '?') {
                            ++count;
                        }
                        ++j;
                    }
                    if (j == m && count > 0) {
                        replaced = true;
                        done += count;
                        fill(target.begin() + i, target.begin() + i + m, '?');
                        res.push_back(i);
                        if (done == n) {
                            reverse(res.begin(), res.end());
                            return res;
                        }
                    }
                }
            }
        }
        return {};
    }
};
// @lc code=end
