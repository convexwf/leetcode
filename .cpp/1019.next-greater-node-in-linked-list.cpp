/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */

// @lc code=start
// 1. 单调栈
// 2023-10-19 submission
// 76/76 cases passed
// Runtime: 72 ms, faster than 55.15% of cpp online submissions.
// Memory Usage:  MB, less than 30.96% of cpp online submissions.
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int, int>> s;
        int index = 0;
        while (head) {
            res.push_back(0);
            while (!s.empty() && s.top().second < head->val) {
                res[s.top().first] = head->val;
                s.pop();
            }
            s.push({index++, head->val});
            head = head->next;
        }
        return res;
    }
};
// @lc code=end
