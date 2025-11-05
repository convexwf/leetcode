/*
 * @lc app=leetcode id=418 lang=cpp
 *
 * [418] Sentence Screen Fitting
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        int cnt = 0;
        for (int i = 0; i < rows; ++i) {
            int j = 0;
            int len = 0;
            while (len + sentence[j].size() <= cols) {
                len += sentence[j].size() + 1;
                j = (j + 1) % n;
                if (j == 0) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
