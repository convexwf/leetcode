/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
// 1. DFS
// 2023-06-08 submission
// 26/26 cases passed
// Runtime: 8 ms, faster than 23.09% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 42.99% of cpp online submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node* pseudoHead = new Node(0, nullptr, head, nullptr);
        flattenDFS(pseudoHead, head);
        pseudoHead->next->prev = nullptr;
        return pseudoHead->next;
    }

    Node* flattenDFS(Node* prev, Node* curr) {
        if (curr == nullptr) {
            return prev;
        }
        curr->prev = prev;
        prev->next = curr;
        Node* tempNext = curr->next;
        Node* tail = flattenDFS(curr, curr->child);
        curr->child = nullptr;
        return flattenDFS(tail, tempNext);
    }
};
// @lc code=end

// @lc code=start
// 2. 栈
// 2023-06-08 submission
// 26/26 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 42.99% of cpp online submissions.
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        stack<Node*> stk;
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                if (curr->next != nullptr) {
                    stk.push(curr->next);
                }
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
            }
            else if (curr->next == nullptr && !stk.empty()) {
                curr->next = stk.top();
                curr->next->prev = curr;
                stk.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};
// @lc code=end

// @lc code=start
// 3. 迭代
// 2023-06-08 submission
// 26/26 cases passed
// Runtime: 4 ms, faster than 78.9% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 79.94% of cpp online submissions.
class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while (cur) {
            if (cur->child) {
                Node* next = cur->next;
                Node* last = cur->child;
                while (last->next) last = last->next;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
                last->next = next;
                if (next) next->prev = last;
            }
            cur = cur->next;
        }
        return head;
    }
};
// @lc code=end