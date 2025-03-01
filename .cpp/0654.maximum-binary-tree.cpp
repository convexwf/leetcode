/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
// 1. 分治法
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
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int maxIndex = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = build(nums, left, maxIndex - 1);
        root->right = build(nums, maxIndex + 1, right);
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2. 单调栈
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
