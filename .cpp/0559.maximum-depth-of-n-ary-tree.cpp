/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
// 1. dfs
// 2024-11-06 submission
// 38/38 cases passed
// Runtime: 17 ms, faster than 18.97% of cpp online submissions.
// Memory Usage: 14.3 MB, less than 99.14% of cpp online submissions.
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
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int depth = 0;
        for (Node* child : root->children) {
            depth = max(depth, maxDepth(child));
        }
        return depth + 1;
    }
};
// @lc code=end
