/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
// 2020-11-29 submission
// 105/105 cases passed
// Runtime: 21 ms, faster than 91.84% of C++ online submissions.
// Memory Usage: 10.5 MB, less than 92.82% of C++ online submissions.
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (char c : s)
            count[c - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
