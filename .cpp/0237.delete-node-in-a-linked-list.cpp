/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
// 1. 节点赋值
// 2022-08-26 submission
// 41/41 cases passed
// Runtime: 19 ms, faster than 54.72% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 39.26% of cpp online submissions.
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
    void deleteNode(ListNode* node) {
        if (nullptr == node || nullptr == node->next) return;
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};
// @lc code=end
