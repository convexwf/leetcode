/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
// 1. 哈希表+贪心算法
// 2024-12-03 submission
// 118/118 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 60.93% of cpp online submissions.
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }
        vector<int> res;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); ++i) {
            right = max(right, last[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return res;
    }
};
// @lc code=end
