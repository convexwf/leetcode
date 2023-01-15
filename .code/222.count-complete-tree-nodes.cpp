/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (60.06%)
 * Likes:    7014
 * Dislikes: 393
 * Total Accepted:    523.8K
 * Total Submissions: 872.1K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a complete binary tree, return the number of the nodes in
 * the tree.
 *
 * According to Wikipedia, every level, except possibly the last, is completely
 * filled in a complete binary tree, and all nodes in the last level are as far
 * left as possible. It can have between 1 and 2^h nodes inclusive at the last
 * level h.
 *
 * Design an algorithm that runs in less than O(n) time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5,6]
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5 * 10^4].
 * 0 <= Node.val <= 5 * 10^4
 * The tree is guaranteed to be complete.
 *
 *
 */

// @lc code=start
// 2020-11-04 submission (brute force)
// 18/18 cases passed
// Runtime: 44 ms, faster than 75.82% of C++ online submissions.
// Memory Usage: 30.7 MB, less than 99.83% of C++ online submissions.
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

// @lc code=start
// 2020-11-04 submission (完美二叉树)
// 18/18 cases passed
// Runtime: 24 ms, faster than 99.37% of C++ online submissions.
// Memory Usage: 31 MB, less than 8.43% of C++ online submissions.
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
    int countNodes(TreeNode* root) {
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while (pLeft) {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    // 全递归形式
    // int countNodes(TreeNode* root) {
    //     int hLeft = leftHeight(root);
    //     int hRight = rightHeight(root);
    //     if (hLeft == hRight) return pow(2, hLeft) - 1;
    //     return countNodes(root->left) + countNodes(root->right) + 1;
    // }
    // int leftHeight(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + leftHeight(root->left);
    // }
    // int rightHeight(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + rightHeight(root->right);
    // }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 18/18 cases passed
// Runtime: 39 ms, faster than 85.04% of C++ online submissions.
// Memory Usage: 30.8 MB, less than 93.87% of C++ online submissions.
class Solution {
public:
    int countNodes(TreeNode* root) {
        int res = 0, h = getHeight(root);
        if (h < 0) return 0;
        if (getHeight(root->right) == h - 1) return (1 << h) + countNodes(root->right);
        return (1 << (h - 1)) + countNodes(root->left);
    }
    int getHeight(TreeNode* node) {
        return node ? (1 + getHeight(node->left)) : -1;
    }
    // 迭代形式
    // int countNodes(TreeNode* root) {
    //     int res = 0, h = getHeight(root);
    //     if (h < 0) return 0;
    //     while (root) {
    //         if (getHeight(root->right) == h - 1) {
    //             res += 1 << h;
    //             root = root->right;
    //         } else {
    //             res += 1 << (h - 1);
    //             root = root->left;
    //         }
    //         --h;
    //     }
    //     return res;
    // }
    // int getHeight(TreeNode* node) {
    //     return node ? (1 + getHeight(node->left)) : -1;
    // }
};
// @lc code=end