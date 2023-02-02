/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
 *
 * https://leetcode.com/problems/construct-string-from-binary-tree/description/
 *
 * algorithms
 * Easy (63.83%)
 * Likes:    2467
 * Dislikes: 2978
 * Total Accepted:    210.5K
 * Total Submissions: 329.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given the root of a binary tree, construct a string consisting of
 * parenthesis and integers from a binary tree with the preorder traversal way,
 * and return it.
 *
 * Omit all the empty parenthesis pairs that do not affect the one-to-one
 * mapping relationship between the string and the original binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4]
 * Output: "1(2(4))(3)"
 * Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to
 * omit all the unnecessary empty parenthesis pairs. And it will be
 * "1(2(4))(3)"
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,null,4]
 * Output: "1(2()(4))(3)"
 * Explanation: Almost the same as the first example, except we cannot omit the
 * first parenthesis pair to break the one-to-one mapping relationship between
 * the input and the output.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
// 2021-12-23 submission
// 160/160 cases passed
// Runtime: 38 ms, faster than 36.03% of C++ online submissions.
// Memory Usage: 53.8 MB, less than 25.41% of C++ online submissions.
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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string res = to_string(root->val);
        if (!root->left && !root->right) return res;
        res += "(" + tree2str(root->left) + ")";
        if (root->right) res += "(" + tree2str(root->right) + ")";
        return res;
    }
};
// @lc code=end
