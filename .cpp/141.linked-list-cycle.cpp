/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
// 1. 哈希表
// 2024-02-23 submission
// 26/26 cases passed
// Runtime: 15 ms, faster than 19.29% of cpp online submissions.
// Memory Usage: 14.3 MB, less than 5.33% of cpp online submissions.
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (nullptr != head) {
            if (visited.count(head)) {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 快慢指针
// 2022-08-02 submission
// 21/21 cases passed
// Runtime: 12 ms, faster than 78.06% of cpp online submissions.
// Memory Usage: 8.1 MB, less than 17.02% of cpp online submissions.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
// @lc code=end
