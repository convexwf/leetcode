/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
// 2021-03-18 submission
// 93/93 cases passed
// Runtime: 18 ms, faster than 75.34% of cpp online submissions.
// Memory Usage: 24.1 MB, less than 90.26% of cpp online submissions.
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
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }

    int helper(TreeNode* root, int& k) {
        if (!root) return -1;
        int val = helper(root->left, k);
        if (k == 0) return val;
        if (--k == 0) return root->val;
        return helper(root->right, k);
    }
};
// @lc code=end

// @lc code=start
// 2023-02-10 submission
// 93/93 cases passed
// Runtime: 18 ms, faster than 75.34% of cpp online submissions.
// Memory Usage: 24.2 MB, less than 66.94% of cpp online submissions.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if (k <= cnt) {
            return kthSmallest(root->left, k);
        }
        else if (k > cnt + 1) {
            return kthSmallest(root->right, k - cnt - 1);
        }
        return root->val;
    }
    int count(TreeNode* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
};
// @lc code=end

// @lc code=start
// Follow up
// 2023-02-10 submission
// 93/93 cases passed
// Runtime: 31 ms, faster than 18.9% of cpp online submissions.
// Memory Usage: 27.2 MB, less than 5.96% of cpp online submissions.
class Solution {
public:
    struct MyTreeNode
    {
        int val;
        int count;
        MyTreeNode* left;
        MyTreeNode* right;
        MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {
        }
    };

    MyTreeNode* build(TreeNode* root) {
        if (!root) return NULL;
        MyTreeNode* node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if (node->left) node->count += node->left->count;
        if (node->right) node->count += node->right->count;
        return node;
    }

    int kthSmallest(TreeNode* root, int k) {
        MyTreeNode* node = build(root);
        return helper(node, k);
    }

    int helper(MyTreeNode* node, int k) {
        if (node->left) {
            int cnt = node->left->count;
            if (k <= cnt) {
                return helper(node->left, k);
            }
            else if (k > cnt + 1) {
                return helper(node->right, k - 1 - cnt);
            }
            return node->val;
        }
        else {
            if (k == 1) return node->val;
            return helper(node->right, k - 1);
        }
    }
};
// @lc code=end
