# Arithmetic

## 2. Add Two Numbers

解题思路

1. 题目描述：需要相加的两个数字通过链表反向存储，结果也需要通过链表反向存储。
2. dummy节点

关联专题

1. **Arithmetic**

```C++
// 2018-04-12 submission
// Runtime: 28 ms, faster than 90.44% of C++ online submissions for Add Two Numbers.
// Memory Usage: 71.6 MB, less than 33.89% of C++ online submissions for Add Two Numbers.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        
        ListNode* cur = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) carry += l1->val;
            if (l2) carry += l2->val;
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};
```

## 43. Multiply Strings

## 67. Add Binary

## 371. Sum of Two Integers

## 415. Add Strings

## 445. Add Two Numbers II

## 989. Add to Array-Form of Integer
