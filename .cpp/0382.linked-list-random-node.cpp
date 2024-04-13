/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */

// @lc code=start
// 2022-08-19 submission
// 8/8 cases passed
// Runtime: 46 ms, faster than 22.4% of cpp online submissions.
// Memory Usage: 16.7 MB, less than 51.7% of cpp online submissions.
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
    Solution(ListNode *head) {
        this->head = head;
    }

    int getRandom() {
        int res = 0, cnt = 1;
        ListNode *cur = head;
        while (cur) {
            int j = rand() % cnt;
            if (j == 0) res = cur->val;
            ++cnt;
            cur = cur->next;
        }
        return res;
    }

private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
