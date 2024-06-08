/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
// 1. 递归中序遍历+排序
// 2023-02-09 submission
// 82/82 cases passed
// Runtime: 7 ms, faster than 96.34% of cpp online submissions.
// Memory Usage: 21.7 MB, less than 54.7% of cpp online submissions.
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
// 2. 递归中序遍历+区间收缩
// 2023-02-09 submission
// 82/82 cases passed
// Runtime: 14 ms, faster than 61.68% of cpp online submissions.
// Memory Usage: 21.7 MB, less than 54.7% of cpp online submissions.
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
// 3. 递归中序遍历+前驱节点
// 2024-06-05 submission
// 85/85 cases passed
// Runtime: 9 ms, faster than 47.94% of cpp online submissions.
// Memory Usage: 20.1 MB, less than 88.44% of cpp online submissions.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long pre = LONG_MIN;
        return inorder(root, pre);
    }

    bool inorder(TreeNode* root, long& pre) {
        if (root == nullptr) {
            return true;
        }
        if (!inorder(root->left, pre)) {
            return false;
        }
        if (root->val <= pre) {
            return false;
        }
        pre = root->val;
        return inorder(root->right, pre);
    }
};
// @lc code=end

// @lc code=start
// 4. Morris 遍历
// 2023-02-09 submission
// 82/82 cases passed
// Runtime: 7 ms, faster than 96.34% of cpp online submissions.
// Memory Usage: 21.8 MB, less than 54.7% of cpp online submissions.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        TreeNode *cur = root, *pre, *parent = NULL;
        bool res = true;
        while (cur) {
            if (!cur->left) {
                if (parent && parent->val >= cur->val) res = false;
                parent = cur;
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
