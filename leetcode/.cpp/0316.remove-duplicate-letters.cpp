/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
// 1. 栈+哈希表
// 2023-10-05 submission
// 290/290 cases passed
// Runtime: 2 ms, faster than 60.85% of cpp online submissions.
// Memory Usage:  MB, less than 77.52% of cpp online submissions.
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        string res;
        int visited = 0;
        for (int i = 0; i < s.size(); i++) {
            if (visited & (1 << (s[i] - 'a'))) {
                continue;
            }
            while (!res.empty() && res.back() > s[i] && last[res.back() - 'a'] > i) {
                visited &= ~(1 << (res.back() - 'a'));
                res.pop_back();
            }
            res.append(1, s[i]);
            visited |= (1 << (s[i] - 'a'));
        }
        return res;
    }
};
// @lc code=end
