/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
// 1. 迭代(头插法)
// 2022-11-14 submission
// 28/28 cases passed
// Runtime: 12 ms, faster than 57.29% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 78.98% of cpp online submissions.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while (head) {
            ListNode* t = head->next;
            head->next = newHead;
            newHead = head;
            head = t;
        }
        return newHead;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2022-11-14 submission
// 28/28 cases passed
// Runtime: 20 ms, faster than 9.16% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 18.47% of cpp online submissions.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
// @lc code=end
