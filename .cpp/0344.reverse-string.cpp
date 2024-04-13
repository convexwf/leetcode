/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
// 2023-01-14 submission
// 477/477 cases passed
// Runtime: 11 ms, faster than 99.73% of cpp online submissions.
// Memory Usage: 23.3 MB, less than 5.07% of cpp online submissions.
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
// @lc code=end
