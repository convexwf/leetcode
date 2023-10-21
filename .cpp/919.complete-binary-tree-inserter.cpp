/*
 * @lc app=leetcode id=919 lang=cpp
 *
 * [919] Complete Binary Tree Inserter
 */

// @lc code=start
// 1. 队列
// 2023-10-20 submission
// 84/84 cases passed
// Runtime: 16 ms, faster than 66.55% of cpp online submissions.
// Memory Usage: 22.9 MB, less than 35.21% of cpp online submissions.
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        root_ = root;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (!node->left || !node->right) {
                break;
            }
            q.push(node->left);
            q.push(node->right);
            q.pop();
        }
    }

    int insert(int v) {
        TreeNode* node = q.front();
        if (!node->left) {
            node->left = new TreeNode(v);
        }
        else {
            node->right = new TreeNode(v);
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        return node->val;
    }

    TreeNode* get_root() {
        return root_;
    }

private:
    TreeNode* root_;
    queue<TreeNode*> q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

// @lc code=start
// 2. 数组
// 2023-10-20 submission
// 84/84 cases passed
// Runtime: 15 ms, faster than 73.24% of cpp online submissions.
// Memory Usage: 22.8 MB, less than 35.21% of cpp online submissions.
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        nodes.push_back(root);
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i]->left) nodes.push_back(nodes[i]->left);
            if (nodes[i]->right) nodes.push_back(nodes[i]->right);
        }
    }

    int insert(int v) {
        int n = nodes.size();
        TreeNode* node = new TreeNode(v);
        nodes.push_back(node);
        if (n % 2 == 1) {
            nodes[(n - 1) / 2]->left = node;
        }
        else {
            nodes[(n - 1) / 2]->right = node;
        }
        return nodes[(n - 1) / 2]->val;
    }

    TreeNode* get_root() {
        return nodes[0];
    }

private:
    vector<TreeNode*> nodes;
};
// @lc code=end
