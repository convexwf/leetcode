/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
// 1. 递归
// 2022-07-19 submission
// 208/208 cases passed
// Runtime: 10 ms, faster than 30.21% of cpp online submissions.
// Memory Usage: 10.7 MB, less than 74.43% of cpp online submissions.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head, n);
    }

    ListNode* helper(ListNode* curr, int& limit) {
        if (!curr) return nullptr;
        curr->next = helper(curr->next, limit);
        --limit;
        if (limit == 0) {
            return curr->next;
        }
        return curr;
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代+快慢指针
// 2022-07-19 submission
// 208/208 cases passed
// Runtime: 14 ms, faster than 9.34% of cpp online submissions.
// Memory Usage: 10.7 MB, less than 74.43% of cpp online submissions.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0) {
            return nullptr;
        }
        ListNode *pre = head, *cur = head;
        while (n > 0 && cur != nullptr) {
            cur = cur->next;
            --n;
        }

        // 链表数量小于 n
        if (n > 0) return head;
        // 链表数量等于 n
        if (cur == nullptr) {
            ListNode* res = head->next;
            delete head;
            return res;
        }

        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* to_delete = pre->next;
        pre->next = pre->next->next;
        delete to_delete;
        return head;
    }
};
// @lc code=end
