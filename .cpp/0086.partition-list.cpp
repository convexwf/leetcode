/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
// 1. 交换节点
// 2023-01-14 submission
// 168/168 cases passed
// Runtime: 4 ms, faster than 59.58% of cpp online submissions.
// Memory Usage: 13.4 MB, less than 29.98% of cpp online submissions.
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
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        // cur 指向第一个大于等于 x 的节点
        // pre 指向最后一个小于 x 的节点
        while (cur && cur->val < x) {
            pre = cur;
            cur = cur->next;
        }
        // 如果 cur 为空，说明链表中没有大于等于 x 的节点
        if (!cur) return head;

        while (cur->next) {
            // 如果下一个节点小于 x
            // 将这个节点移到 pre 的后面
            if (cur->next->val < x) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            }
            // 否则，cur 向后移动
            else {
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
// 2. 重建链表
// 2023-01-14 submission
// 168/168 cases passed
// Runtime: 7 ms, faster than 71.83% of cpp online submissions.
// Memory Usage: 10.2 MB, less than 94.44% of cpp online submissions.
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
                p->next = nullptr;
            }
            else {
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
