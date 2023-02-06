/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (43.09%)
 * Likes:    4589
 * Dislikes: 982
 * Total Accepted:    806.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^5].
 * -1000 <= Node.val <= 1000
 * 
 * 
 */

// @lc code=start
// 2023-02-02 submission
// 52/52 cases passed
// Runtime: 286 ms, faster than 65.62% of C++ online submissions.
// Memory Usage: 145 MB, less than 15.55% of C++ online submissions.
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
// @lc code=end

// @lc code=start
// 2023-02-02 submission
// 52/52 cases passed
// Runtime: 289 ms, faster than 60.45% of C++ online submissions.
// Memory Usage: 144.7 MB, less than 54.33% of C++ online submissions.
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            ++res;
            for (int i = q.size(); i > 0; --i) {
                auto t = q.front(); q.pop();
                if (!t->left && !t->right) return res;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return -1;
    }
};
// @lc code=end