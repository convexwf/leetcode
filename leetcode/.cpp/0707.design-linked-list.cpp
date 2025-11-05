/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
// 1. 双向链表实现
// 2023-07-12 submission
// 65/65 cases passed
// Runtime: 45 ms, faster than 65.84% of cpp online submissions.
// Memory Usage: 19.8 MB, less than 15.25% of cpp online submissions.
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1.
     */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* cur = head->next;
        while (index--) cur = cur->next;
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion,
     * the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the
     * length of linked list, the node will be appended to the end of linked list. If index is
     * greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        Node* cur = head;
        while (index--) cur = cur->next;
        Node* node = new Node(val);
        node->next = cur->next;
        node->prev = cur;
        cur->next->prev = node;
        cur->next = node;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* cur = head;
        while (index--) cur = cur->next;
        cur->next->next->prev = cur;
        cur->next = cur->next->next;
        size--;
    }

private:
    struct Node
    {
        int val;
        Node* prev;
        Node* next;
        Node(int v) : val(v), prev(nullptr), next(nullptr) {
        }
    };
    Node* head;
    Node* tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

// @lc code=start
// 2. 单向链表实现
// 2023-07-12 submission
// 65/65 cases passed
// Runtime: 53 ms, faster than 18.18% of cpp online submissions.
// Memory Usage: 19.7 MB, less than 43.27% of cpp online submissions.
class MyLinkedList {
private:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {
        }
    };
    ListNode* head;
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(0);
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1.
     */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* cur = head->next;
        while (index--) cur = cur->next;
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion,
     * the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
        ++size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the
     * length of linked list, the node will be appended to the end of linked list. If index is
     * greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        ListNode* node = new ListNode(val);
        ListNode* cur = head;
        while (index--) cur = cur->next;
        node->next = cur->next;
        cur->next = node;
        ++size;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        ListNode* cur = head;
        while (index--) cur = cur->next;
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        --size;
    }
};
// @lc code=end
