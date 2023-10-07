/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
// 2020-11-08 submission (栈)
// 1563/1563 cases passed
// Runtime: 46 ms, faster than 42.32% of C++ online submissions.
// Memory Usage: 73.8 MB, less than 20.44% of C++ online submissions.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *res = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {sum += s1.top(); s1.pop();}
            if (!s2.empty()) {sum += s2.top(); s2.pop();}
            res->val = sum % 10;
            ListNode *head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
};
// @lc code=end

// @lc code=start
// 2020-11-08 submission (递归)
// 1563/1563 cases passed
// Runtime: 36 ms, faster than 75.25% of C++ online submissions.
// Memory Usage: 71.3 MB, less than 69.2% of C++ online submissions.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getLength(l1), n2 = getLength(l2);
        ListNode *head = new ListNode(1);
        head->next = (n1 > n2) ? helper(l1, l2, n1 - n2) : helper(l2, l1, n2 - n1);
        if (head->next->val > 9) {
            head->next->val %= 10;
            return head;
        }
        return head->next;
    }
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int diff) {
        if (!l1) return NULL;
        ListNode *res = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
        ListNode *post = (diff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, diff - 1);
        if (post && post->val > 9) {
            post->val %= 10;
            ++res->val;
        }
        res->next = post;
        return res;
    }
};
// @lc code=end
