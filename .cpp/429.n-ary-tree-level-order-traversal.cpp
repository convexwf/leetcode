/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
// 1. 迭代
// 2023-09-19 submission
// 38/38 cases passed
// Runtime: 13 ms, faster than 76.5% of cpp online submissions.
// Memory Usage: 12.3 MB, less than 5.11% of cpp online submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto child : node->children) {
                    q.push(child);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2023-09-19 submission
// 38/38 cases passed
// Runtime: 7 ms, faster than 99.39% of cpp online submissions.
// Memory Usage:  MB, less than 37.6% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }

private:
    void helper(Node* root, int level, vector<vector<int>>& res) {
        if (root == nullptr) return;
        if (res.size() <= level) res.resize(level + 1);
        res[level].push_back(root->val);
        for (auto child : root->children) {
            helper(child, level + 1, res);
        }
    }
};
// @lc code=end
