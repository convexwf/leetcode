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

解题思路

1. 两数相乘得到的乘积的长度其实其实不会超过两个数字的长度之和
2. num1 中位置为 i 的数字乘以 num2 中位置为 j 的数字，那么得到的两位数字的位置为 i+j 和 i+j+1。
3. 注意处理结果为 0 的情况

```C++
// 2019-09-17 submission
// Runtime: 4 ms, faster than 89.68% of C++ online submissions for Multiply Strings.
// Memory Usage: 7.2 MB, less than 50.27% of C++ online submissions for Multiply Strings.
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> vec(num1.size() + num2.size() - 1, 0);
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                vec[i+j] += (num1[num1.size()-i-1]-'0') * (num2[num2.size()-j-1]-'0');
            }
        }
        
        int carry = 0;
        string res;
        for (int i = 0; i < vec.size(); i++) {
            carry += vec[i];
            res.insert(0, 1, carry % 10 + '0');
            carry /= 10;
        }
        if (carry) res.insert(0, 1, carry % 10 + '0');
        return *res.begin() == '0' ? "0" : res;
    }
};
```

## 67. Add Binary

## 371. Sum of Two Integers

## 415. Add Strings

## 445. Add Two Numbers II

## 989. Add to Array-Form of Integer
