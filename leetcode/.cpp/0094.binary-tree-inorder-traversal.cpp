/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
// 1. 递归
// 2023-02-09 submission
// 70/70 cases passed
// Runtime: 6 ms, faster than 20.68% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 45.69% of cpp online submissions.
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    void inorder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        if (root->left) inorder(root->left, res);
        res.push_back(root->val);
        if (root->right) inorder(root->right, res);
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代+栈
// 2023-02-09 submission
// 70/70 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 92.54% of cpp online submissions.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. Morris遍历
// 2023-02-09 submission
// 70/70 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 77.94% of cpp online submissions.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *cur, *pre;
        cur = root;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else {
                pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end
