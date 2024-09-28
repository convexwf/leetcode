/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

// @lc code=start
// 1. 递归
// 2023-06-19 submission
// 92/92 cases passed
// Runtime: 46 ms, faster than 20.22% of cpp online submissions.
// Memory Usage: 32.6 MB, less than 55.4% of cpp online submissions.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            }
            else {
                TreeNode* cur = root->right;
                while (cur->left) cur = cur->left;
                root->val = cur->val;
                root->right = deleteNode(root->right, cur->val);
            }
        }
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2023-06-19 submission
// 92/92 cases passed
// Runtime: 44 ms, faster than 29.79% of cpp online submissions.
// Memory Usage: 32.6 MB, less than 55.4% of cpp online submissions.
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        if (!pre) return del(cur);
        if (pre->left && pre->left->val == key) {
            pre->left = del(cur);
        }
        else {
            pre->right = del(cur);
        }
        return root;
    }

    // 删除结点，返回新的根结点
    TreeNode* del(TreeNode* node) {
        if (!node) return nullptr;
        // 如果右子结点不存在，直接返回左子结点
        if (!node->right) return node->left;
        // 如果右子结点存在，找到右子树中的最小值，即右子树中的最左子结点
        //  将要删除结点的左子结点连接到右子树的最左子结点的左子结点上
        TreeNode* t = node->right;
        while (t->left) t = t->left;
        t->left = node->left;
        // 返回要删除结点的右子结点
        TreeNode* res = node->right;
        delete node;
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 通用删除
// 2023-06-19 submission
// 92/92 cases passed
// Runtime: 39 ms, faster than 59.36% of cpp online submissions.
// Memory Usage: 32.6 MB, less than 55.4% of cpp online submissions.
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->right) {
                return root->left;
            }
            else {
                TreeNode* cur = root->right;
                while (cur->left) cur = cur->left;
                swap(root->val, cur->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end
