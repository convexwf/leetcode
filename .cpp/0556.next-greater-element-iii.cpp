/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start
// 1. 字符串处理+两次遍历
// 2022-08-26 submission
// 39/39 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 93.88% of cpp online submissions.
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size(), i = len - 2, j = len - 1;
        while (i >= 0 && str[i] >= str[i + 1]) --i;
        if (i < 0) return -1;
        while (str[j] <= str[i]) --j;
        swap(str[i], str[j]);
        reverse(str.begin() + i + 1, str.end());
        long long res = stoll(str);
        return res > INT_MAX ? -1 : res;
    }
};
// @lc code=end
