/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
// 2022-11-14 submission
// 66/66 cases passed
// Runtime: 50 ms, faster than 53.95% of C++ online submissions.
// Memory Usage: 15 MB, less than 79.87% of C++ online submissions.
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode *cur = head;
        while (cur->next) {
            if (cur->next->val == val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head->val == val ? head->next : head;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-14 submission
// 66/66 cases passed
// Runtime: 36 ms, faster than 74.92% of C++ online submissions.
// Memory Usage: 15.3 MB, less than 13.39% of C++ online submissions.
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
// @lc code=end