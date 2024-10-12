/*
 * @lc app=leetcode id=294 lang=cpp
 *
 * [294] Flip Game II
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    bool canWin(string currentState) {
        for (int i = 1; i < currentState.size(); ++i) {
            if (currentState[i] == '+' && currentState[i - 1] == '+') {
                currentState[i] = currentState[i - 1] = '-';
                if (!canWin(currentState)) {
                    return true;
                }
                currentState[i] = currentState[i - 1] = '+';
            }
        }
        return false;
    }
};
// @lc code=end
