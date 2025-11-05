/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
// 1. 快慢指针+递归
// 2020-09-14 submission
// 32/32 cases passed
// Runtime: 35 ms, faster than 59.3% of cpp online submissions.
// Memory Usage: 28.4 MB, less than 64.93% of cpp online submissions.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }

    TreeNode* helper(ListNode* start, ListNode* end) {
        if (start == end) return nullptr;
        if (start->next == end) return new TreeNode(start->val);

        // Find the middle point
        ListNode *fast = start, *middle = start;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            middle = middle->next;
        }

        return new TreeNode(middle->val, helper(start, middle), helper(middle->next, end));
    }
};
// @lc code=end

// @lc code=start
// 2. 快慢指针+递归+链表断开
// 2023-01-14 submission
// 32/32 cases passed
// Runtime: 25 ms, faster than 88.15% of cpp online submissions.
// Memory Usage: 28.3 MB, less than 64.93% of cpp online submissions.
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *last = slow;
        while (fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = nullptr;
        TreeNode* cur = new TreeNode(slow->val);
        if (head != slow) cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(fast);
        return cur;
    }
};
// @lc code=end
