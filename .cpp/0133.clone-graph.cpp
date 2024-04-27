/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
// 1. 哈希表+dfs
// 2020-11-11 submission
// 22/22 cases passed
// Runtime: 16 ms, faster than 26.07% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 49.44% of cpp online submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return helper(node, m);
    }

    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return node;
        if (m.count(node)) return m[node];
        Node* res = new Node(node->val);
        m[node] = res;
        for (Node* neighbor : node->neighbors) {
            res->neighbors.push_back(helper(neighbor, m));
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+bfs
// 2022-11-17 submission
// 22/22 cases passed
// Runtime: 21 ms, faster than 5.24% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 93.22% of cpp online submissions.
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, Node*> m;
        queue<Node*> q{{node}};
        Node* clone = new Node(node->val);
        m[node] = clone;
        while (!q.empty()) {
            Node* t = q.front();
            q.pop();
            for (Node* neighbor : t->neighbors) {
                if (!m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[t]->neighbors.push_back(m[neighbor]);
            }
        }
        return clone;
    }
};
// @lc code=end
