/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
// 1. 递归
// 2022-11-15 submission
// 38/38 cases passed
// Runtime: 50 ms, faster than 52.46% of cpp online submissions.
// Memory Usage: 11.3 MB, less than 28.04% of cpp online submissions.
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(Node* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);
        for (Node* child : node->children) {
            helper(child, res);
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代+栈
// 2022-11-15 submission
// 38/38 cases passed
// Runtime: 61 ms, faster than 23.68% of cpp online submissions.
// Memory Usage: 11.1 MB, less than 90.47% of cpp online submissions.
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> res;
        stack<Node*> st{{root}};
        while (!st.empty()) {
            Node* t = st.top();
            st.pop();
            res.push_back(t->val);
            for (int i = (int)t->children.size() - 1; i >= 0; --i) {
                st.push(t->children[i]);
            }
        }
        return res;
    }
};
// @lc code=end
