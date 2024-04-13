/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
// 1. 递归
// 2023-08-14 submission
// 107/107 cases passed
// Runtime: 81 ms, faster than 74.72% of cpp online submissions.
// Memory Usage: 52.7 MB, less than 24.92% of cpp online submissions.
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        auto maxIt = max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*maxIt);
        vector<int> left(nums.begin(), maxIt);
        vector<int> right(maxIt + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2. 单调栈
// 2023-08-14 submission
// 107/107 cases passed
// Runtime: 61 ms, faster than 94.87% of cpp online submissions.
// Memory Usage: 39.3 MB, less than 91.49% of cpp online submissions.
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for (int i = 0; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            while (!stk.empty() && stk.top()->val < nums[i]) {
                cur->left = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.top()->right = cur;
            }
            stk.push(cur);
        }
        while (stk.size() > 1) {
            stk.pop();
        }
        return stk.top();
    }
};
// @lc code=end

// @lc code=start
// 3. 单调栈-数组实现
// 2023-08-14 submission
// 107/107 cases passed
// Runtime: 67 ms, faster than 89.45% of cpp online submissions.
// Memory Usage: 39.4 MB, less than 91.49% of cpp online submissions.
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> v;
        for (int num : nums) {
            TreeNode* cur = new TreeNode(num);
            while (!v.empty() && v.back()->val < num) {
                cur->left = v.back();
                v.pop_back();
            }
            if (!v.empty()) {
                v.back()->right = cur;
            }
            v.push_back(cur);
        }
        return v.front();
    }
};
// @lc code=end
