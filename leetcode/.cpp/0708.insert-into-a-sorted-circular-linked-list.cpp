/*
 * @lc app=leetcode id=708 lang=cpp
 *
 * [708] Insert into a Sorted Circular Linked List
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }
        Node* cur = head;
        while (cur->next != head) {
            if (cur->val <= insertVal && cur->next->val >= insertVal) {
                break;
            }
            if (cur->val > cur->next->val &&
                (insertVal >= cur->val || insertVal <= cur->next->val)) {
                break;
            }
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        return head;
    }
};
// @lc code=end
