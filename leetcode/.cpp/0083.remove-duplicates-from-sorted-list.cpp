/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
// 1. 迭代
// 2022-07-28 submission
// 166/166 cases passed
// Runtime: 10 ms, faster than 88.01% of cpp online submissions.
// Memory Usage: 11.4 MB, less than 97.36% of cpp online submissions.
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
        if (!head) return nullptr;
        ListNode* cur = head;
        while (nullptr != cur) {
            while (cur->next && cur->val == cur->next->val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            cur = cur->next;
        }
        return head;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2022-07-28 submission
// 166/166 cases passed
// Runtime: 13 ms, faster than 73.89% of cpp online submissions.
// Memory Usage: 11.6 MB, less than 79.46% of cpp online submissions.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        while (head->next && head->val == head->next->val) {
            head = head->next;
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
// @lc code=end
