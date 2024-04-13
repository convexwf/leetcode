/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
// 1. DFS+哈希表
// 2024-02-05 submission
// 57/57 cases passed
// Runtime: 7 ms, faster than 40.04% of cpp online submissions.
// Memory Usage: 15.4 MB, less than 27.14% of cpp online submissions.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<int> visited;
        vector<int> res;
        dfs(root, parent);
        findK(target, k, parent, visited, res);
        return res;
    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root->left) {
            parent[root->left] = root;
            dfs(root->left, parent);
        }
        if (root->right) {
            parent[root->right] = root;
            dfs(root->right, parent);
        }
    }

    void findK(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& parent,
               unordered_set<int>& visited, vector<int>& res) {
        if (root == nullptr || visited.count(root->val)) {
            return;
        }
        visited.insert(root->val);
        if (k == 0) {
            res.push_back(root->val);
            return;
        }
        findK(root->left, k - 1, parent, visited, res);
        findK(root->right, k - 1, parent, visited, res);
        findK(parent[root], k - 1, parent, visited, res);
    }
};
// @lc code=end

// @lc code=start
// 2. BFS+哈希表
// 2024-02-05 submission
// 57/57 cases passed
// Runtime: 4 ms, faster than 66.69% of cpp online submissions.
// Memory Usage: 15.5 MB, less than 24.29% of cpp online submissions.
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parent;
        unordered_set<int> visited;
        queue<TreeNode*> q;
        vector<int> res;
        function<void(TreeNode*)> findParent = [&](TreeNode* node) {
            if (node->left) {
                parent[node->left->val] = node;
                findParent(node->left);
            }
            if (node->right) {
                parent[node->right->val] = node;
                findParent(node->right);
            }
        };
        findParent(root);
        q.push(target);
        visited.insert(target->val);
        while (!q.empty() && k > 0) {
            int qsize = q.size();
            while (qsize-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                for (TreeNode* n : {node->left, node->right, parent[node->val]}) {
                    if (nullptr != n && !visited.count(n->val)) {
                        q.push(n);
                        visited.insert(n->val);
                    }
                }
            }
            --k;
        }
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
// @lc code=end
