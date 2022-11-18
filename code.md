## 109. Convert Sorted List to Binary Search Tree

解题思路

1. 递归，通过双指针法找到链表中心，然后一切为二，分别建立左子树和右子树

```C++
// 2020-09-14 submission

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL);
    }

    TreeNode* helper(ListNode* start, ListNode* end) {
        if (start == end) return NULL;
        if (start->next == end) return new TreeNode(start->val);

        // Find the middle point
        ListNode* fast=start, *middle=start;
        while(fast!=end && fast->next!=end) {
            fast = fast->next->next;
            middle = middle->next;
        }

        return new TreeNode(middle->val, helper(start, middle), helper(middle->next, end));
    }
};
```

## 110. Balanced Binary Tree

```C++
// 2018-07-22 submission
// ?/? cases passed
// Runtime: 12 ms, faster than 85.09% of C++ online submissions.
// Memory Usage: 21.7 MB, less than 67.92% of C++ online submissions.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int h = 0;
        return helper(root, h);
    }

    bool helper(TreeNode* root, int& h) {
        if (!root) {
            h = 0;
            return true;
        }
        int l_h = 0, r_h = 0;
        bool res = helper(root->left, l_h) && helper(root->right, r_h);
        h = max(l_h, r_h) + 1;
        return res && abs(l_h - r_h) <= 1;
    }
};
```
