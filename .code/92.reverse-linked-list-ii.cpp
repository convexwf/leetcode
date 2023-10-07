/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
// 2022-11-14 submission
// 44/44 cases passed
// Runtime: 6 ms, faster than 38.14% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 18.46% of C++ online submissions.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0), *prev = dummy;
        dummy->next = head;
        for (int i = 0; i < m-1; i++)
            {prev = prev->next;}
        ListNode* cur = prev->next;
        for (int i = m; i < n; i++) {
            ListNode* t = cur->next;
            cur->next = t->next;
            t->next = prev->next;
            prev->next = t;
        }
        return dummy->next;
    }
};
// @lc code=end