/*
 * @lc app=leetcode id=255 lang=cpp
 *
 * [255] Verify Preorder Sequence in Binary Search Tree
 */

// @lc code=start
// 1. 单调栈
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int root = 0;
        for (int num : preorder) {
            if (num < root) {
                return false;
            }
            while (!stk.empty() && num > stk.top()) {
                root = stk.top();
                stk.pop();
            }
            stk.push(num);
        }
        return true;
    }
};
// @lc code=end
