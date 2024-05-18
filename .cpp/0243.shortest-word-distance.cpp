/*
 * @lc app=leetcode id=243 lang=cpp
 *
 * [243] Shortest Word Distance
 */

// @lc code=start
// 1. 双指针
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int p1 = -1, p2 = -1;
        int res = n;
        for (int i = 0; i < n; ++i) {
            if (wordsDict[i] == word1) {
                p1 = i;
            } else if (wordsDict[i] == word2) {
                p2 = i;
            }
            if (p1 != -1 && p2 != -1) {
                res = min(res, abs(p1 - p2));
            }
        }
        return res;
    }
};
// @lc code=end
