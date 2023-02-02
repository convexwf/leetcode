/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.52%)
 * Likes:    6737
 * Dislikes: 191
 * Total Accepted:    773.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: [[1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
// 2023-01-31 submission
// 33/33 cases passed
// Runtime: 7 ms, faster than 31.59% of C++ online submissions.
// Memory Usage: 13 MB, less than 5.18% of C++ online submissions.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }

    void helper(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (res.size() <= level) {
            res.push_back({});
        }
        vector<int> &oneLevel = res[level];
        if (level % 2 == 0) oneLevel.push_back(node->val);
        else oneLevel.insert(oneLevel.begin(), node->val);
        helper(node->left, level + 1, res);
        helper(node->right, level + 1, res);
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 33/33 cases passed
// Runtime: 3 ms, faster than 76.22% of C++ online submissions.
// Memory Usage: 12.2 MB, less than 17% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        bool leftToRight = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> oneLevel(size);
            for (int i = 0; i < size; ++i) {
                TreeNode *t = q.front(); q.pop();
                int idx = leftToRight ? i : (size - 1 - i);
                oneLevel[idx] = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            leftToRight = !leftToRight;
            res.push_back(oneLevel);
        }
        return res;
    }
};
// @lc code=end