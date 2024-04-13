/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
// 2023-01-14 submission
// 90/90 cases passed
// Runtime: 267 ms, faster than 68.79% of cpp online submissions.
// Memory Usage: 123.2 MB, less than 35.5% of cpp online submissions.
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
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        stack<int> st;
        while (cur) {
            st.push(cur->val);
            cur = cur->next;
        }
        while (head) {
            int t = st.top();
            st.pop();
            if (head->val != t) return false;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 90/90 cases passed
// Runtime: 263 ms, faster than 72.06% of cpp online submissions.
// Memory Usage: 121.2 MB, less than 39.81% of cpp online submissions.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        return helper(head, cur);
    }
    bool helper(ListNode* node, ListNode*& cur) {
        if (!node) return true;
        bool res = helper(node->next, cur) && (cur->val == node->val);
        cur = cur->next;
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2020-12-05 submission
// 90/90 cases passed
// Runtime: 247 ms, faster than 82.75% of cpp online submissions.
// Memory Usage: 118.6 MB, less than 49.6% of cpp online submissions.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast)
            return helper(head, slow->next, slow);
        else
            return helper(head, slow, slow);
    }

    bool helper(ListNode* head, ListNode*& after, ListNode* stop) {
        if (head == stop) return true;
        bool res = helper(head->next, after, stop) && (head->val == after->val);
        after = after->next;
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 90/90 cases passed
// Runtime: 280 ms, faster than 58.34% of cpp online submissions.
// Memory Usage: 118.1 MB, less than 50.87% of cpp online submissions.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *pre = head;
        while (last->next) {
            ListNode* tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};
// @lc code=end
