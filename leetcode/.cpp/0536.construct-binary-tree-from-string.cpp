/*
 * @lc app=leetcode id=536 lang=cpp
 *
 * [536] Construct Binary Tree from String
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        int i = 0;
        return build(s, i);
    }

    TreeNode* build(string& s, int& i) {
        int start = i;
        while (i < s.size() && (isdigit(s[i]) || s[i] == '-')) i++;
        int val = stoi(s.substr(start, i - start));
        TreeNode* node = new TreeNode(val);
        if (i < s.size() && s[i] == '(') {
            i++;
            node->left = build(s, i);
            i++;
        }
        if (i < s.size() && s[i] == '(') {
            i++;
            node->right = build(s, i);
            i++;
        }
        return node;
    }
};
// @lc code=end
