/*
 * @lc app=leetcode id=663 lang=cpp
 *
 * [663] Equal Tree Partition
 */

// @lc code=start
// 1. dfs+哈希表
class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> mp;
        int sum = dfs(root, mp);
        if (sum == 0) [return mp[sum] > 1;] return sum % 2 == 0 && mp.count(sum / 2) > 0;
    }

    int dfs(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root) {
            return 0;
        }
        int sum = root->val + dfs(root->left, mp) + dfs(root->right, mp);
        mp[sum]++;
        return sum;
    }
};
// @lc code=end
