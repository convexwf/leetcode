/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
// 2023-01-14 submission
// 168/168 cases passed
// Runtime: 7 ms, faster than 71.83% of C++ online submissions.
// Memory Usage: 10.2 MB, less than 94.44% of C++ online submissions.
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;;
        while (pre->next && pre->next->val < x) pre = pre->next;
        cur = pre;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// 链表变化顺序为：
// 1 -> 4 -> 3 -> 2 -> 5 -> 2
// 1 -> 2 -> 4 -> 3 -> 5 -> 2
// 1 -> 2 -> 2 -> 4 -> 3 -> 5
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 168/168 cases passed
// Runtime: 7 ms, faster than 71.83% of C++ online submissions.
// Memory Usage: 10.2 MB, less than 94.44% of C++ online submissions.
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};
// 链表变化顺序为：
// Original: 1 -> 4 -> 3 -> 2 -> 5 -> 2
// New:

// Original: 4 -> 3 -> 2 -> 5 -> 2
// New:　  1

// Original: 4 -> 3 -> 5 -> 2
// New:　  1 -> 2

// Original: 4 -> 3 -> 5
// New:　  1 -> 2 -> 2

// Original:
// New:　  1 -> 2 -> 2 -> 4 -> 3 -> 5
// @lc code=end