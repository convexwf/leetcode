/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
// 1. 迭代
// 2022-11-14 submission
// 44/44 cases passed
// Runtime: 6 ms, faster than 38.14% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 18.46% of cpp online submissions.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0), *pre = dummy;
        dummy->next = head;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode* start = pre->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* then = start->next;
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
        }
        return dummy->next;
    }
};
// @lc code=end
