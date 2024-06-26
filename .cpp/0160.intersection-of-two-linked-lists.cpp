/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
// 1. 链表拼接+双指针
// 2022-11-14 submission
// 39/39 cases passed
// Runtime: 44 ms, faster than 97.66% of cpp online submissions.
// Memory Usage: 14.6 MB, less than 33.27% of cpp online submissions.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;
    }
};
// @lc code=end

// @lc code=start
// 2. 链表长度求差值
// 2022-11-14 submission
// 39/39 cases passed
// Runtime: 120 ms, faster than 29.32% of cpp online submissions.
// Memory Usage: 14.6 MB, less than 33.27% of cpp online submissions.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; ++i) {
                headB = headB->next;
            }
        }
        else {
            for (int i = 0; i < lenA - lenB; ++i) {
                headA = headA->next;
            }
        }
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return (headA && headB) ? headA : nullptr;
    }

    int getLength(ListNode *head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
};
// @lc code=end
