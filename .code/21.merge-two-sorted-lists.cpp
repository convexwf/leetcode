/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
// 2022-08-01 submission
// 208/208 cases passed
// Runtime: 13 ms, faster than 48.02% of C++ online submissions.
// Memory Usage: 14.9 MB, less than 42.37% of C++ online submissions.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-01 submission
// 208/208 cases passed
// Runtime: 12 ms, faster than 56.69% of C++ online submissions.
// Memory Usage: 14.8 MB, less than 81.4% of C++ online submissions.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end