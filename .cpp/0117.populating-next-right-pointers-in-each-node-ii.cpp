/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
// 2020-11-09 submission
// 55/55 cases passed
// Runtime: 15 ms, faster than 89.57% of cpp online submissions.
// Memory Usage: 17.6 MB, less than 18.64% of cpp online submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            Node* cur = NULL;
            for (int i = 0; i < q_size; i++) {
                cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                cur->next = (i == q_size - 1 ? NULL : q.front());
                cur = cur->next;
            }
        }
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2020-11-09 submission
// 55/55 cases passed
// Runtime: 17 ms, faster than 84.28% of cpp online submissions.
// Memory Usage: 17.3 MB, less than 94.92% of cpp online submissions.
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        if (root->left)
            root->left->next = (root->right != nullptr ? root->right : findNext(root->next));
        if (root->right) root->right->next = findNext(root->next);

        connect(root->right);
        connect(root->left);
        return root;
    }

    Node* findNext(Node* curr) {
        if (!curr) return NULL;
        if (curr->left) return curr->left;
        if (curr->right) return curr->right;
        return findNext(curr->next);
    }
};
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 55/55 cases passed
// Runtime: 23 ms, faster than 68.31% of cpp online submissions.
// Memory Usage: 17.4 MB, less than 83.64% of cpp online submissions.
// Non-recursion, constant space
class Solution {
public:
    Node* connect(Node* root) {
        Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
        while (root) {
            if (root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if (root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
            if (!root) {
                cur = dummy;
                root = dummy->next;
                dummy->next = NULL; // 必须清空，否则会死循环
            }
        }
        return head;
    }
};
// @lc code=end
