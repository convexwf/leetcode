/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
 */

// @lc code=start
// 1. 哈希表
// 2023-09-06 submission
// 57/57 cases passed
// Runtime: 32 ms, faster than 67.81% of cpp online submissions.
// Memory Usage: 21.3 MB, less than 69.85% of cpp online submissions.
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        while (head) {
            if (st.count(head->val) && (!head->next || !st.count(head->next->val))) {
                res++;
            }
            head = head->next;
        }
        return res;
    }
};
// class Solution {
// public:
//     int numComponents(ListNode* head, vector<int>& nums) {
//         unordered_set<int> numSet(nums.begin(), nums.end());
//         int res = 0;
//         while (head) {
//             if (numSet.count(head->val) {
//                 res++;
//                 while (head && numSet.count(head->val)) {
//                     head = head->next;
//                 }
//             }
//             if (head) {
//                 head = head->next;
//             }
//         }
//         return res;
//     }
// };
// @lc code=end
