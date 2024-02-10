/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
// 2022-11-15 submission
// 38/38 cases passed
// Runtime: 59 ms, faster than 27.09% of C++ online submissions.
// Memory Usage: 11.3 MB, less than 25.13% of C++ online submissions.
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(Node* node, vector<int>& res) {
        if (!node) return;
        for (Node* child : node->children) {
            helper(child, res);
        }
        res.push_back(node->val);
    }
};
// @lc code=end

// @lc code=start
// 2022-11-15 submission
// 38/38 cases passed
// Runtime: 69 ms, faster than 9.85% of C++ online submissions.
// Memory Usage: 11.1 MB, less than 91.8% of C++ online submissions.
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int> res;
        stack<Node*> st{{root}};
        while (!st.empty()) {
            Node *t = st.top(); st.pop();
            res.insert(res.begin(), t->val);
            for (Node* child : t->children) {
                if (child) st.push(child);
            }
        }
        return res;
    }
};
// @lc code=end