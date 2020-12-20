

## 5. Longest Palindromic Substring

解题思路

1. 题目描述：求给定字符串的最长子回文串

## 9. Palindrome Number

解题思路

1. 题目描述：判断一个整数是否是回文数

## 125. Valid Palindrome

解题思路

1. 题目描述：验证一个给定的字符串是否为回文。有效字符值包含字母和数字，其他视作跳过。

## 131. Palindrome Partitioning

解题思路

1. 题目描述：找到所有对给定字符串可能拆分成回文串的情况

## 234. Palindrome Linked List

解题思路

1. 快慢指针+递归：首先通过快慢指针找到中间指针，然后通过递归比较值。注意要在递归返回时才处理值比较，所以需要传入需要比较的指针作为引用。

```C++
// 2020-12-05 submission
// Runtime: 24 ms, faster than 71.04% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 15.3 MB, less than 18.17% of C++ online submissions for Palindrome Linked List.
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
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) return helper(head, slow->next, slow);
        else return helper(head, slow, slow);
    }

    bool helper(ListNode* head, ListNode*& after, ListNode* stop) {
        if (head == stop) return true;
        bool flag = helper(head->next, after, stop);
        flag = flag && (head->val == after->val);
        after = after->next;
        return flag;
    }
};
```