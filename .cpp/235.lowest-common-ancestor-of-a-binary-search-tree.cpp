/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
// 2022-08-26 submission
// 28/28 cases passed
// Runtime: 38 ms, faster than 72.28% of cpp online submissions.
// Memory Usage: 23.3 MB, less than 13.83% of cpp online submissions.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-26 submission
// 28/28 cases passed
// Runtime: 70 ms, faster than 5.02% of cpp online submissions.
// Memory Usage: 23.2 MB, less than 65.03% of cpp online submissions.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val > max(p->val, q->val))
                root = root->left;
            else if (root->val < min(p->val, q->val))
                root = root->right;
            else
                break;
        }
        return root;
    }
};
// @lc code=end
