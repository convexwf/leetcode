/*
 * @lc app=leetcode id=716 lang=cpp
 *
 * [716] Max Stack
 */

// @lc code=start
// 1. 双向链表+有序集合
class DoubleLinkedList {
public:
    int val;
    DoubleLinkedList* prev;
    DoubleLinkedList* next;
    DoubleLinkedList(int val) : val(val), prev(nullptr), next(nullptr) {
    }
};

class MaxStack {
public:
    MaxStack() {
        head = new DoubleLinkedList(0);
        tail = new DoubleLinkedList(0);
        head->next = tail;
        tail->prev = head;
    }

    ~MaxStack() {
        DoubleLinkedList* node = head;
        while (node) {
            DoubleLinkedList* tmp = node;
            node = node->next;
            delete tmp;
        }
    }

    void push(int x) {
        DoubleLinkedList* node = new DoubleLinkedList(x);
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        max_set[x].push_back(node);
    }

    int pop() {
        DoubleLinkedList* node = tail->prev;
        int val = node->val;
        node->prev->next = tail;
        tail->prev = node->prev;
        max_set[val].pop_back();
        if (max_set[val].empty()) {
            max_set.erase(val);
        }
        delete node;
        return val;
    }

    int top() {
        return tail->prev->val;
    }

    int peekMax() {
        return max_set.rbegin()->first;
    }

    int popMax() {
        int max_val = max_set.rbegin()->first;
        DoubleLinkedList* node = max_set[max_val].back();
        max_set[max_val].pop_back();
        if (max_set[max_val].empty()) {
            max_set.erase(max_val);
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        return max_val;
    }

private:
    DoubleLinkedList* head;
    DoubleLinkedList* tail;
    std::map<int, vector<DoubleLinkedList*>> max_set;
};
// @lc code=end
