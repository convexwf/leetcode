/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (38.82%)
 * Likes:    11199
 * Dislikes: 515
 * Total Accepted:    1.5M
 * Total Submissions: 3.9M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
 *
 */

// @lc code=start
// 2022-07-19 submission
// 208/208 cases passed
// Runtime: 10 ms, faster than 30.21% of C++ online submissions.
// Memory Usage: 10.7 MB, less than 74.43% of C++ online submissions.
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
        if(!curr) return NULL;
        curr->next = helper(curr->next, limit);
        --limit;
        if(limit != 0) return curr;
        else return curr->next;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-19 submission
// 208/208 cases passed
// Runtime: 14 ms, faster than 9.34% of C++ online submissions.
// Memory Usage: 10.7 MB, less than 74.43% of C++ online submissions.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0) {
            return NULL;
        }
        ListNode *pre = head, *cur = head;
        while (n > 0 && cur != NULL) {
            cur = cur->next;
            --n;
        }

        // 链表数量小于 n
        if (n > 0) return head;
        // 链表数量等于 n
        if (cur == NULL) {
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