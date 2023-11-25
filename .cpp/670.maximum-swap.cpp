/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
// 1. 贪心算法
// 2023-11-24 submission
// 112/112 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 51.86% of cpp online submissions.
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 9; j > s[i] - '0'; --j) {
                if (last[j] > i) {
                    swap(s[i], s[last[j]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};
// @lc code=end
