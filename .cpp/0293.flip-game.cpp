/*
 * @lc app=leetcode id=293 lang=cpp
 *
 * [293] Flip Game
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        for (int i = 1; i < currentState.size(); ++i) {
            if (currentState[i] == '+' && currentState[i - 1] == '+') {
                currentState[i] = currentState[i - 1] = '-';
                res.push_back(currentState);
                currentState[i] = currentState[i - 1] = '+';
            }
        }
        return res;
    }
};
// @lc code=end
