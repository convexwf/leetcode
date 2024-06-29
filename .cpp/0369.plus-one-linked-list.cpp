/*
 * @lc app=leetcode id=369 lang=cpp
 *
 * [369] Plus One Linked List
 */

// @lc code=start
// 1. 递归
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (dfs(head) == 1) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }

    int dfs(ListNode* node) {
        if (node == nullptr) {
            return 1;
        }
        int value = dfs(node->next) + node->val;
        node->val = value % 10;
        return value / 10;
    }
};
// @lc code=end
