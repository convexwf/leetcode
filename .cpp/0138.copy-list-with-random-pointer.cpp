/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
// 1. 哈希表+递归
// 2020-11-11 submission
// 19/19 cases passed
// Runtime: 27 ms, faster than 5.43% of cpp online submissions.
// Memory Usage: 11.7 MB, less than 8.29% of cpp online submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return helper(head, m);
    }

    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return nullptr;
        if (m.count(node)) return m[node];
        Node* res = new Node(node->val);
        m[node] = res;
        res->next = helper(node->next, m);
        res->random = helper(node->random, m);
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 链表复制+拆分
// 2020-11-11 submission
// 19/19 cases passed
// Runtime: 14 ms, faster than 66.41% of cpp online submissions.
// Memory Usage: 11.1 MB, less than 88.18% of cpp online submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        // 复制节点
        Node* cur = head;
        while (cur) {
            Node* new_node = new Node(cur->val);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = cur->next->next;
        }
        // 复制 random 指针
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // 拆分
        cur = head;
        Node* res = head->next;
        while (cur) {
            Node* t = cur->next;
            cur->next = t->next;
            if (t->next) t->next = t->next->next;
            cur = cur->next;
        }
        return res;
    }
};
// @lc code=end
