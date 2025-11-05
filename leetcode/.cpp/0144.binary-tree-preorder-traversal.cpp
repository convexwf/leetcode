/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
// 1. 递归
// 2023-02-09 submission
// 69/69 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 80.1% of cpp online submissions.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
};
// @lc code=end

// @lc code=start
// 2. 非递归+栈
// 2023-02-09 submission
// 69/69 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 50.42% of cpp online submissions.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            else {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. Morris 遍历
// 2023-02-09 submission
// 69/69 cases passed
// Runtime: 6 ms, faster than 21.19% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 50.42% of cpp online submissions.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> data = {};
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur) {
            if (cur->left == NULL) {
                data.push_back(cur->val);
                cur = cur->right;
            }
            else {
                // 寻找前驱结点
                pre = cur->left;
                while (pre->right != cur && pre->right) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    data.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    cur = cur->right;
                    pre->right = NULL;
                }
            }
        }
        return data;
    }
};
// @lc code=end
