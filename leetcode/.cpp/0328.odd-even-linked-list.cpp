/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

// @lc code=start
// 1. 双指针
// 2023-02-13 submission
// 70/70 cases passed
// Runtime: 15 ms, faster than 50.82% of cpp online submissions.
// Memory Usage: 10.6 MB, less than 37.88% of cpp online submissions.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre = head, *cur = head->next;
        while (cur && cur->next) {
            ListNode* tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        return head;
    }
};
// @lc code=end

// @lc code=start
// 2. 奇偶指针
// 2023-02-13 submission
// 70/70 cases passed
// Runtime: 14 ms, faster than 60.38% of cpp online submissions.
// Memory Usage: 10.3 MB, less than 97.85% of cpp online submissions.
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *even_head = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};
// @lc code=end
