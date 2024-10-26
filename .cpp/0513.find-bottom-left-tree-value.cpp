/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */

// @lc code=start
// 1. bfs+层序遍历
// 2023-06-06 submission
// 77/77 cases passed
// Runtime: 3 ms, faster than 99.51% of cpp online submissions.
// Memory Usage: 21.8 MB, less than 59.18% of cpp online submissions.
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
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (i == 0) res = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. dfs+前序遍历
// 2023-06-06 submission
// 77/77 cases passed
// Runtime: 11 ms, faster than 80.49% of cpp online submissions.
// Memory Usage: 21.6 MB, less than 83.88% of cpp online submissions.
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0, maxDepth = 0;
        dfs(root, 1, maxDepth, res);
        return res;
    }

private:
    void dfs(TreeNode* root, int depth, int& maxDepth, int& res) {
        if (root == nullptr) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = root->val;
        }
        dfs(root->left, depth + 1, maxDepth, res);
        dfs(root->right, depth + 1, maxDepth, res);
    }
};
// @lc code=end

// @lc code=start
// 3. bfs+层序遍历（从右往左遍历）
// 2023-06-06 submission
// 77/77 cases passed
// Runtime: 15 ms, faster than 50.6% of cpp online submissions.
// Memory Usage: 21.8 MB, less than 59.18% of cpp online submissions.
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (root->right) q.push(root->right);
            if (root->left) q.push(root->left);
        }
        return root->val;
    }
};
// @lc code=end
