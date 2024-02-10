/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

// @lc code=start
// 2023-02-09 submission
// 68/68 cases passed
// Runtime: 6 ms, faster than 20.13% of C++ online submissions.
// Memory Usage: 8.5 MB, less than 47.17% of C++ online submissions.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode *root, vector<int> &res) {
        if (!root) return;
        if (root->left) helper(root->left, res);
        if (root->right) helper(root->right, res);
        res.push_back(root->val);
    }
};
// @lc code=end

// @lc code=start
// 2023-02-09 submission
// 68/68 cases passed
// Runtime: 6 ms, faster than 20.13% of C++ online submissions.
// Memory Usage: 8.5 MB, less than 73.21% of C++ online submissions.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            } else {
                TreeNode *t = s.top(); s.pop();
                p = t->left;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-09 submission
// 68/68 cases passed
// Runtime: 6 ms, faster than 20.13% of C++ online submissions.
// Memory Usage: 8.2 MB, less than 98.65% of C++ online submissions.
class Solution {
public:
    // addPath
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.push_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *p1 = root, *p2 = nullptr;
        // p2的设定是p1的左孩子

        // p1非空就继续循环
        while (p1 != nullptr) {
            p2 = p1->left;
            // 若p1有左孩子
            if (p2 != nullptr) {
                // p2是p1左子树的最右节点
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                // p2->right == nullptr 确定了该节点是第一次访问
                // 先把p1加入结果，再把p1左子树的最右节点指向p1，p1继续往左走
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                // // p2->right == p1 说明该节点已经访问过，此时再访问到就置为空
                } else {
                    p2->right = nullptr;
                    // 打印p1->left而非p1，就保证根节点一定是最后打印的
                    addPath(res, p1->left);
                }
            }
            // 1、其左孩子已经访问完毕，因此把p1的右孩子赋给p1
            // 要么就是在回溯的路上，要么就是到了一个全新的未被访问过的节点
            p1 = p1->right;
        }
        // 最后打印root及其右孩子（若右孩子是叶子节点）
        addPath(res, root);
        return res;
    }
};
// @lc code=end