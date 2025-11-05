/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 */

// @lc code=start
// 1. 递归+哈希表
// 2023-12-14 submission
// 306/306 cases passed
// Runtime: 7 ms, faster than 79.2% of cpp online submissions.
// Memory Usage: 26.2 MB, less than 36.54% of cpp online submissions.
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < postorder.size(); ++i) {
            m[postorder[i]] = i;
        }
        return dfs(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1, m);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& postorder, int preLeft, int preRight,
                  int postLeft, int postRight, unordered_map<int, int>& m) {
        if (preLeft > preRight) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preLeft]);
        if (preLeft == preRight) {
            return root;
        }
        int idx = m[preorder[preLeft + 1]];
        root->left =
            dfs(preorder, postorder, preLeft + 1, preLeft + 1 + idx - postLeft, postLeft, idx, m);
        root->right = dfs(preorder, postorder, preLeft + 1 + idx - postLeft + 1, preRight, idx + 1,
                          postRight - 1, m);
        return root;
    }
};
// @lc code=end
