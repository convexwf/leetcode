/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
// 2023-02-10 submission
// 108/108 cases passed
// Runtime: 7 ms, faster than 20.25% of C++ online submissions.
// Memory Usage: 9.3 MB, less than 20.28% of C++ online submissions.
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
    int sumNumbers(TreeNode* root) {
        return sumNumbersDFS(root, 0);
    }
    int sumNumbersDFS(TreeNode* root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) return sum;
        return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
    }
};
// @lc code=end

// @lc code=start
// 2023-02-10 submission
// 108/108 cases passed
// Runtime: 3 ms, faster than 61.48% of C++ online submissions.
// Memory Usage: 9.4 MB, less than 18.14% of C++ online submissions.
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        stack<TreeNode*> st{{root}};
        while (!st.empty()) {
            TreeNode *t = st.top(); st.pop();
            if (!t->left && !t->right) {
                res += t->val;
            }
            if (t->right) {
                t->right->val += t->val * 10;
                st.push(t->right);
            }
            if (t->left) {
                t->left->val += t->val * 10;
                st.push(t->left);
            }
        }
        return res;
    }
};
// @lc code=end