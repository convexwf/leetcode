/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
// 1. 快慢指针
// 2023-08-07 submission
// 36/36 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 38.86% of cpp online submissions.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end

// @lc code=start
// 2. 计数
// 2023-08-07 submission
// 36/36 cases passed
// Runtime: 4 ms, faster than 33.67% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 38.86% of cpp online submissions.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        n /= 2;
        cur = head;
        while (n--) {
            cur = cur->next;
        }
        return cur;
    }
};
// @lc code=end
