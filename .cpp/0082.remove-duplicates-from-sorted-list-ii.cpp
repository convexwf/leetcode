/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
// 1. 迭代+dummy节点
// 2022-07-28 submission
// 166/166 cases passed
// Runtime: 5 ms, faster than 92.15% of cpp online submissions.
// Memory Usage: 11.1 MB, less than 58.16% of cpp online submissions.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next) {
            ListNode* cur = pre->next;
            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            if (cur != pre->next)
                pre->next = cur->next;
            else
                pre = pre->next;
        }
        return dummy->next;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2022-07-28 submission
// 166/166 cases passed
// Runtime: 9 ms, faster than 76.35% of cpp online submissions.
// Memory Usage: 11 MB, less than 91.09% of cpp online submissions.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* cur = head;
        while (head->next && head->val == head->next->val) {
            head = head->next;
        }
        head->next = deleteDuplicates(head->next);
        if (head != cur) {
            return head->next;
        }
        return head;
    }
};
// @lc code=end
