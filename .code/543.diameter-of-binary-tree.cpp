/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (56.49%)
 * Likes:    10637
 * Dislikes: 672
 * Total Accepted:    973K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the root of a binary tree, return the length of the diameter of the
 * tree.
 *
 * The diameter of a binary tree is the length of the longest path between any
 * two nodes in a tree. This path may or may not pass through the root.
 *
 * The length of a path between two nodes is represented by the number of edges
 * between them.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 *
 *
 */

// @lc code=start
// 2021-03-17 submission
// 104/104 cases passed
// Runtime: 12 ms, faster than 62.53% of C++ online submissions.
// Memory Usage: 23.2 MB, less than 8.76% of C++ online submissions.
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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        int res = 0;
        maxDepth(root, res, m);
        return res;
    }
    int maxDepth(TreeNode* node, int& res, unordered_map<TreeNode*, int>& m) {
        if (!node) return 0;
        if (m.count(node)) return m[node];
        int left = maxDepth(node->left, res, m);
        int right = maxDepth(node->right, res, m);
        res = max(res, left + right);
        return m[node] = (max(left, right) + 1);
    }
};
// @lc code=end
