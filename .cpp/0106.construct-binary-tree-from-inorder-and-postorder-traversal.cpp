/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
// 1. 分治法+哈希表
// 2022-11-17 submission
// 202/202 cases passed
// Runtime: 12 ms, faster than 58.3% of cpp online submissions.
// Memory Usage: 26.3 MB, less than 28.29% of cpp online submissions.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, index);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight,
                        int postLeft, int postRight, unordered_map<int, int>& index) {
        if (inLeft > inRight) {
            return nullptr;
        }
        int rootVal = postorder[postRight];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = index[rootVal];
        int leftSize = rootIndex - inLeft;
        root->left = buildTree(inorder, postorder, inLeft, rootIndex - 1, postLeft,
                               postLeft + leftSize - 1, index);
        root->right = buildTree(inorder, postorder, rootIndex + 1, inRight, postLeft + leftSize,
                                postRight - 1, index);
        return root;
    }
};
// @lc code=end
