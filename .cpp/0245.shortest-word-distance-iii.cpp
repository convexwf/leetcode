/*
 * @lc app=leetcode id=245 lang=cpp
 *
 * [245] Shortest Word Distance III
 */

// @lc code=start
// 1. 双指针
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                p1 = i;
            }
            if (wordsDict[i] == word2) {
                if (word1 == word2) {
                    p1 = p2;
                }
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
