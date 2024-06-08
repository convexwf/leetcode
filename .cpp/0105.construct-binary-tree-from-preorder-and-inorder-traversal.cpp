/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
// 1. 分治法
// 2022-11-17 submission
// 203/203 cases passed
// Runtime: 84 ms, faster than 22.26% of cpp online submissions.
// Memory Usage: 25.9 MB, less than 93.19% of cpp online submissions.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder,
                        int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) return nullptr;
        int i = 0;
        for (i = iLeft; i <= iRight; ++i) {
            if (preorder[pLeft] == inorder[i]) break;
        }
        TreeNode* cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return cur;
    }
};
// @lc code=end

// @lc code=start
// 2. 分治法+哈希表
// 2024-06-05 submission
// 203/203 cases passed
// Runtime: 15 ms, faster than 45.7% of cpp online submissions.
// Memory Usage:  MB, less than 44.73% of cpp online submissions.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, index);
    }

    TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder,
                        int inLeft, int inRight, unordered_map<int, int>& index) {
        if (preLeft > preRight) {
            return nullptr;
        }
        int preRoot = preLeft;
        int inRoot = index[preorder[preRoot]];
        TreeNode* root = new TreeNode(preorder[preRoot]);
        int leftSize = inRoot - inLeft;
        root->left = buildTree(preorder, preLeft + 1, preLeft + leftSize, inorder, inLeft,
                               inRoot - 1, index);
        root->right = buildTree(preorder, preLeft + leftSize + 1, preRight, inorder, inRoot + 1,
                                inRight, index);
        return root;
    }
};
// @lc code=end
