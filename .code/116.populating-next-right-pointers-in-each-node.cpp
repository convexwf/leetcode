/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
// 2022-11-17 submission
// 59/59 cases passed
// Runtime: 37 ms, faster than 64.35% of C++ online submissions.
// Memory Usage: 16.7 MB, less than 86.72% of C++ online submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() {}
    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        if (root->left) root->left->next = root->right;
        if (root->right && root->next) root->right->next = root->next->left;
        // if (root->right) root->right->next = root->next? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 59/59 cases passed
// Runtime: 10 ms, faster than 99.82% of C++ online submissions.
// Memory Usage: 16.8 MB, less than 86.72% of C++ online submissions.
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node *start = root, *cur = NULL;
        while (start->left) {
            cur = start;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
        return root;
    }
};
// @lc code=end