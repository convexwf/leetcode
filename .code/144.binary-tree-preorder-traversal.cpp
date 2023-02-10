/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (63.76%)
 * Likes:    4654
 * Dislikes: 137
 * Total Accepted:    1M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */

// @lc code=start
// 2023-02-09 submission
// 69/69 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 8.4 MB, less than 80.1% of C++ online submissions.
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
// 2023-02-09 submission
// 69/69 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 8.4 MB, less than 50.42% of C++ online submissions.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                p = st.top(); st.pop();
                p = p->right;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-09 submission
// 69/69 cases passed
// Runtime: 6 ms, faster than 21.19% of C++ online submissions.
// Memory Usage: 8.4 MB, less than 50.42% of C++ online submissions.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> data = {};
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur)
        {
            if (cur->left == NULL)
            {
                data.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                // 寻找前驱结点
                pre = cur->left;
                while (pre->right != cur && pre->right)
                {
                    pre = pre->right;
                }
                if (pre->right == NULL)
                {
                    data.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    cur = cur->right;
                    pre->right = NULL;
                }
            }
        }
        return data;
    }
};
// @lc code=end