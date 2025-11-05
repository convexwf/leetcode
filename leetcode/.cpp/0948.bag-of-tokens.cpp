/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
// 1. 贪婪算法
// 2023-09-20 submission
// 147/147 cases passed
// Runtime: 4 ms, faster than 82.08% of cpp online submissions.
// Memory Usage: 11.1 MB, less than 5.78% of cpp online submissions.
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int score = 0, maxScore = 0;
        int left = 0, right = tokens.size() - 1;
        while (left <= right) {
            if (P >= tokens[left]) {
                P -= tokens[left++];
                score++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0) {
                P += tokens[right--];
                score--;
            }
            else {
                break;
            }
        }
        return maxScore;
    }
};
// @lc code=end
