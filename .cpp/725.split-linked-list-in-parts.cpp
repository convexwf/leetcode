/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */

// @lc code=start
// 1. brute force
// 2023-08-22 submission
// 43/43 cases passed
// Runtime: 3 ms, faster than 96.59% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 79.96% of cpp online submissions.
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        int size = n / k, remain = n % k;
        vector<ListNode*> res(k, nullptr);
        cur = head;
        for (int i = 0; i < k && cur; ++i) {
            res[i] = cur;
            int curSize = size + (i < remain ? 1 : 0);
            for (int j = 0; j < curSize - 1; ++j) {
                cur = cur->next;
            }
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return res;
    }
};
// @lc code=end
