/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
// 1. 递归
// 2024-12-11 submission
// 18/18 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 31.4 MB, less than 9.13% of cpp online submissions.
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
// 2. 递归+优化
// 2020-11-04 submission
// 18/18 cases passed
// Runtime: 24 ms, faster than 99.37% of cpp online submissions.
// Memory Usage: 31 MB, less than 8.43% of cpp online submissions.
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
        if (hLeft == hRight) {
            return pow(2, hLeft) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    // 全递归形式
    // int countNodes(TreeNode* root) {
    //     int hLeft = leftHeight(root);
    //     int hRight = rightHeight(root);
    //     if (hLeft == hRight) return pow(2, hLeft) - 1;
    //     return countNodes(root->left) + countNodes(root->right) + 1;
    // }
    //
    // int leftHeight(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + leftHeight(root->left);
    // }
    //
    // int rightHeight(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + rightHeight(root->right);
    // }
};
// @lc code=end

// @lc code=start
// 3. 递归+高度计算
// 2023-01-14 submission
// 18/18 cases passed
// Runtime: 39 ms, faster than 85.04% of cpp online submissions.
// Memory Usage: 30.8 MB, less than 93.87% of cpp online submissions.
class Solution {
public:
    int countNodes(TreeNode* root) {
        int res = 0, h = getHeight(root);
        if (h < 0) {
            return 0;
        }
        if (getHeight(root->right) == h - 1) {
            return (1 << h) + countNodes(root->right);
        }
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
