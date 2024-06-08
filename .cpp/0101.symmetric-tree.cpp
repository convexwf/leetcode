/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
// 1. 递归
// 2024-06-05 submission
// 199/199 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 17.3 MB, less than 72.64% of cpp online submissions.
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
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }

    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代+双向队列
// 2024-06-05 submission
// 199/199 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 17.8 MB, less than 5.06% of cpp online submissions.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        deque<TreeNode*> q;
        q.push_back(root->left);
        q.push_back(root->right);
        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop_front();
            TreeNode* right = q.back();
            q.pop_back();
            if (left == nullptr && right == nullptr) {
                continue;
            }
            if (left == nullptr || right == nullptr || left->val != right->val) {
                return false;
            }
            q.push_front(left->right);
            q.push_front(left->left);
            q.push_back(right->left);
            q.push_back(right->right);
        }
        return true;
    }
};
// @lc code=end
