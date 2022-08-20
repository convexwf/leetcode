/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 *
 * https://leetcode.com/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (76.88%)
 * Likes:    3817
 * Dislikes: 156
 * Total Accepted:    536.8K
 * Total Submissions: 698.2K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * You are given the root of a binary search tree (BST) and an integer val.
 *
 * Find the node in the BST that the node's value equals val and return the
 * subtree rooted with that node. If such a node does not exist, return
 * null.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [4,2,7,1,3], val = 2
 * Output: [2,1,3]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [4,2,7,1,3], val = 5
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 5000].
 * 1 <= Node.val <= 10^7
 * root is a binary search tree.
 * 1 <= val <= 10^7
 *
 *
 */

// @lc code=start
// 2022-08-19 submission
// 36/36 cases passed
// Runtime: 60 ms, faster than 60.29% of C++ online submissions.
// Memory Usage: 34.9 MB, less than 22.99% of C++ online submissions.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        return (root->val > val) ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 36/36 cases passed
// Runtime: 37 ms, faster than 98.03% of C++ online submissions.
// Memory Usage: 34.8 MB, less than 22.99% of C++ online submissions.
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            root = (root->val > val) ? root->left : root->right;
        }
        return root;
    }
};
// @lc code=end
