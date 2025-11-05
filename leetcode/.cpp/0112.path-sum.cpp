/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
// 1. 前序遍历
// 2022-07-30 submission
// 117/117 cases passed
// Runtime: 15 ms, faster than 68.33% of cpp online submissions.
// Memory Usage: 21.3 MB, less than 74.49% of cpp online submissions.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        // check if the current node is a leaf
        if (!root->left && !root->right) {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2024-02-07 submission
// 117/117 cases passed
// Runtime: 8 ms, faster than 56.08% of cpp online submissions.
// Memory Usage:  MB, less than 71.61% of cpp online submissions.
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        stack<TreeNode*> st{{root}};
        while (!st.empty()) {
            TreeNode* t = st.top();
            st.pop();
            if (!t->left && !t->right) {
                if (t->val == sum) return true;
            }
            if (t->right) {
                t->right->val += t->val;
                st.push(t->right);
            }
            if (t->left) {
                t->left->val += t->val;
                st.push(t->left);
            }
        }
        return false;
    }
};
// @lc code=end
