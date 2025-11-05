/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
// 插入排序
// 2025-02-08 submission
// 30/30 cases passed
// Runtime: 2875 ms, faster than 5.06% of cpp online submissions.
// Memory Usage: 55.8 MB, less than 99.15% of cpp online submissions.
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            }
            else {
                ListNode* prev = dummy;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummy->next;
    }
};
// @lc code=end

// @lc code=start
// 冒泡排序
// Time Limit Exceeded
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        bool swapped;
        do {
            swapped = false;
            ListNode* current = head;
            while (current->next) {
                if (current->val > current->next->val) {
                    // 交换节点的值
                    std::swap(current->val, current->next->val);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);

        return head;
    }
};
// @lc code=end

// @lc code=start
// 选择排序
// Time Limit Exceeded
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        for (ListNode* i = head; i != nullptr; i = i->next) {
            ListNode* minNode = i;
            for (ListNode* j = i->next; j != nullptr; j = j->next) {
                if (j->val < minNode->val) {
                    minNode = j;
                }
            }
            if (minNode != i) {
                std::swap(i->val, minNode->val);
            }
        }

        return head;
    }
};
// @lc code=end

// @lc code=start
// 归并排序
// 2023-01-14 submission
// 30/30 cases passed
// Runtime: 185 ms, faster than 97.67% of cpp online submissions.
// Memory Usage: 53.4 MB, less than 56.17% of cpp online submissions.
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = sortList(slow->next);
        slow->next = nullptr;
        ListNode* left = sortList(head);

        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            }
            else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = (left != nullptr) ? left : right;
        return dummy->next;
    }
};
// @lc code=end

// @lc code=start
// 快速排序
// Time Limit Exceeded
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        quickSort(head, nullptr);
        return head;
    }

    void quickSort(ListNode* head, ListNode* tail) {
        if (head == tail || head->next == tail) {
            return;
        }

        ListNode* pivot = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != tail) {
            if (fast->val < pivot->val) {
                slow = slow->next;
                swap(slow->val, fast->val);
            }
            fast = fast->next;
        }
        swap(pivot->val, slow->val);

        quickSort(head, slow);
        quickSort(slow->next, tail);
    }
};
// @lc code=end
