/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */

// @lc code=start
// 1. 排序+剪枝+双指针
// 2023-05-23 submission
// 100/100 cases passed
// Runtime: 3 ms, faster than 72.82% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 79.13% of cpp online submissions.
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() > b.size() || (a.size() == b.size() && a < b);
        });
        for (int i = 0; i < strs.size(); ++i) {
            bool flag = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (strs[i].size() > strs[j].size()) break; // 剪枝
                if (isSubsequence(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) return strs[i].size();
        }
        return -1;
    }

private:
    bool isSubsequence(const string& a, const string& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) ++i;
            ++j;
        }
        return i == a.size();
    }
};
// @lc code=end
