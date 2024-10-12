/*
 * @lc app=leetcode id=285 lang=cpp
 *
 * [285] Inorder Successor in BST
 */

// @lc code=start
// 1. 递归+二分查找
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;
        while (root) {
            if (root->val <= p->val) {
                root = root->right;
            }
            else {
                res = root;
                root = root->left;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 栈+中序遍历
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        bool isNext = false;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (isNext) return cur;
            if (cur == p) isNext = true;
            cur = cur->right;
        }
        return nullptr;
    }
};
// @lc code=end
