/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
// 2023-02-09 submission
// 82/82 cases passed
// Runtime: 14 ms, faster than 61.68% of C++ online submissions.
// Memory Usage: 21.7 MB, less than 54.7% of C++ online submissions.
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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* root, long mn, long mx) {
        if (!root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return helper(root->left, mn, root->val) && helper(root->right, root->val, mx);
    }
};
// @lc code=end

// @lc code=start
// 2023-02-09 submission
// 82/82 cases passed
// Runtime: 7 ms, faster than 96.34% of C++ online submissions.
// Memory Usage: 21.7 MB, less than 54.7% of C++ online submissions.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> vals;
        inorder(root, vals);
        for (int i = 0; i < vals.size() - 1; ++i) {
            if (vals[i] >= vals[i + 1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};
// @lc code=end

// @lc code=start
// 2023-02-09 submission
// 82/82 cases passed
// Runtime: 13 ms, faster than 66.09% of C++ online submissions.
// Memory Usage: 21.9 MB, less than 22.58% of C++ online submissions.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        return inorder(root, pre);
    }
    bool inorder(TreeNode* node, TreeNode*& pre) { // pre 表示当前节点的前缀节点
        if (!node) return true;
        bool res = inorder(node->left, pre);
        if (!res) return false;
        if (pre) {
            if (node->val <= pre->val) return false;
        }
        pre = node;
        return inorder(node->right, pre);
    }
};
// @lc code=end

// @lc code=start
// 2023-02-09 submission
// 82/82 cases passed
// Runtime: 7 ms, faster than 96.34% of C++ online submissions.
// Memory Usage: 21.8 MB, less than 54.7% of C++ online submissions.
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        TreeNode *cur = root, *pre, *parent = NULL;
        bool res = true;
        while (cur) {
            if (!cur->left) {
                if (parent && parent->val >= cur->val) res = false;
                parent = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    if (parent->val >= cur->val) res = false;
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end