/*
 * @lc app=leetcode id=272 lang=cpp
 *
 * [272] Closest Binary Search Tree Value II
 */

// @lc code=start
// 1. 中序遍历+队列
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        queue<int> q;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (q.size() < k) {
                q.push(cur->val);
            }
            else {
                if (abs(q.front() - target) > abs(cur->val - target)) {
                    q.pop();
                    q.push(cur->val);
                }
                else {
                    break;
                }
            }
            cur = cur->right;
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end
