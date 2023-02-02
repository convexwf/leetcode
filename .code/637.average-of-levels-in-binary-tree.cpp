/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (71.75%)
 * Likes:    4500
 * Dislikes: 281
 * Total Accepted:    378K
 * Total Submissions: 526.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the average value of the nodes on
 * each level in the form of an array. Answers within 10^-5 of the actual
 * answer will be accepted.
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [3.00000,14.50000,11.00000]
 * Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5,
 * and on level 2 is 11.
 * Hence return [3, 14.5, 11].
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,9,20,15,7]
 * Output: [3.00000,14.50000,11.00000]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */

// @lc code=start
// 2021-12-21 submission
// 66/66 cases passed
// Runtime: 19 ms, faster than 61.5% of C++ online submissions.
// Memory Usage: 22.3 MB, less than 93.47% of C++ online submissions.
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        if (root) q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            double level_sum = 0;
            for (int i = 0; i < q_size; i++) {
                level_sum += q.front()->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(level_sum / q_size);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 66/66 cases passed
// Runtime: 21 ms, faster than 48.74% of C++ online submissions.
// Memory Usage: 22.4 MB, less than 75.45% of C++ online submissions.
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res, cnt;
        helper(root, 0, cnt, res);
        for (int i = 0; i < res.size(); ++i) {
            res[i] /= cnt[i];
        }
        return res;
    }

    void helper(TreeNode* node, int level, vector<double>& cnt, vector<double>& res) {
        if (!node) return;
        if (res.size() <= level) {
            res.push_back(0);
            cnt.push_back(0);
        }
        res[level] += node->val;
        ++cnt[level];
        helper(node->left, level + 1, cnt, res);
        helper(node->right, level + 1, cnt, res);
    }
};
// @lc code=end