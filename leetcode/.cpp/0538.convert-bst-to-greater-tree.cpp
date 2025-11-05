/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 */

// @lc code=start
// 1. 反向中序遍历
// 2023-06-14 submission
// 215/215 cases passed
// Runtime: 44 ms, faster than 50.14% of cpp online submissions.
// Memory Usage: 33.4 MB, less than 45.58% of cpp online submissions.
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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }

private:
    void convert(TreeNode* root, int& sum) {
        if (root == nullptr) return;
        convert(root->right, sum);
        sum += root->val;
        root->val = sum;
        convert(root->left, sum);
    }
};
// @lc code=end

// @lc code=start
// 2. 栈
// 2023-06-14 submission
// 215/215 cases passed
// Runtime: 47 ms, faster than 34.57% of cpp online submissions.
// Memory Usage: 33.6 MB, less than 19.33% of cpp online submissions.
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->right;
            }
            p = st.top();
            st.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }
        return root;
    }
};
// @lc code=end

// @lc code=start
// 3. morris 遍历
// 2023-06-14 submission
// 215/215 cases passed
// Runtime: 47 ms, faster than 34.57% of cpp online submissions.
// Memory Usage: 33.4 MB, less than 45.58% of cpp online submissions.
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->right == nullptr) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            else {
                TreeNode* succ = getSuccessor(node);
                if (succ->left == nullptr) {
                    succ->left = node;
                    node = node->right;
                }
                else {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }
        return root;
    }

    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }
};
// @lc code=end