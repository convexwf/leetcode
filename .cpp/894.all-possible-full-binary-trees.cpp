/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 */

// @lc code=start
// 1. 递归
// 2023-10-27 submission
// 20/20 cases passed
// Runtime: 71 ms, faster than 45.3% of cpp online submissions.
// Memory Usage: 35.7 MB, less than 21.35% of cpp online submissions.
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) return {};
        if (N == 1) return {new TreeNode(0)};
        vector<TreeNode*> res;
        for (int i = 1; i < N; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N - i - 1);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归+哈希表
// 2023-10-27 submission
// 20/20 cases passed
// Runtime: 52 ms, faster than 88.4% of cpp online submissions.
// Memory Usage: 28.8 MB, less than 52.74% of cpp online submissions.
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (n == 1) return {new TreeNode(0)};
        if (memo.count(n)) return memo[n];
        vector<TreeNode*> ans;
        for (int i = 1; i < n; i += 2) {
            for (auto& left : allPossibleFBT(i)) {
                for (auto& right : allPossibleFBT(n - i - 1)) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return memo[n] = ans;
    }

private:
    unordered_map<int, vector<TreeNode*>> memo;
};
// @lc code=end
