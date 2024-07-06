/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
// 1. 链表遍历
// 2022-07-28 submission
// 231/231 cases passed
// Runtime: 11 ms, faster than 63.78% of cpp online submissions.
// Memory Usage: 11.8 MB, less than 54.75% of cpp online submissions.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        int n = 1;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
            n++;
        }
        cur->next = head;
        k = n - k % n;
        while (k--) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};
// @lc code=end

// @lc code=start
// 2. 快慢指针
// 2024-07-05 submission
// 232/232 cases passed
// Runtime: 10 ms, faster than 16.7% of cpp online submissions.
// Memory Usage: 15.1 MB, less than 94.23% of cpp online submissions.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        int n = 1;
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            n++;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        fast = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};
// @lc code=end
