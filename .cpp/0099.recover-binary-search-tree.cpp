/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start
// 1. 递归中序遍历+排序
// 2022-07-23 submission
// 1919/1919 cases passed
// Runtime: 57 ms, faster than 43.77% of cpp online submissions.
// Memory Usage: 59.1 MB, less than 9.32% of cpp online submissions.
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
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        sort(nums.begin(), nums.end());
        int idx = 0;
        recover(root, nums, idx);
    }

    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    void recover(TreeNode* root, vector<int>& nums, int& idx) {
        if (!root) return;
        recover(root->left, nums, idx);
        root->val = nums[idx++];
        recover(root->right, nums, idx);
    }
};
// @lc code=end

// @lc code=start
// 2. 递归中序遍历+数组+交换
// 2024-12-30 submission
// 1919/1919 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 61.3 MB, less than 17.49% of cpp online submissions.
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nums;
        inorder(root, nums);
        auto [x, y] = findTwoSwapped(nums);
        swap(x->val, y->val);
    }

    void inorder(TreeNode* root, vector<TreeNode*>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root);
        inorder(root->right, nums);
    }

    pair<TreeNode*, TreeNode*> findTwoSwapped(vector<TreeNode*>& nums) {
        int n = nums.size();
        TreeNode *x = nullptr, *y = nullptr;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i]->val > nums[i + 1]->val) {
                y = nums[i + 1];
                if (x == nullptr) {
                    x = nums[i];
                }
                else {
                    break;
                }
            }
        }
        return {x, y};
    }
};
// @lc code=end

// @lc code=start
// 3. 递归中序遍历+交换
// 2024-12-30 submission
// 1919/1919 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 33.63% of cpp online submissions.
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x = nullptr, *y = nullptr, *pre = nullptr;
        auto dfs = [&](auto&& self, TreeNode* root) -> void {
            if (root == nullptr) {
                return;
            }
            self(self, root->left);
            if (pre != nullptr && pre->val > root->val) {
                y = root;
                if (x == nullptr) {
                    x = pre;
                }
                else {
                    return;
                }
            }
            pre = root;
            self(self, root->right);
        };
        dfs(dfs, root);
        swap(x->val, y->val);
    }
};
// @lc code=end
