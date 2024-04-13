/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
// 1. 数组实现
// 2023-11-23 submission
// 58/58 cases passed
// Runtime: 22 ms, faster than 45.2% of cpp online submissions.
// Memory Usage: 17.3 MB, less than 6.7% of cpp online submissions.
class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = vector<int>(k);
        head = 0;
        tail = 0;
        size = 0;
        capacity = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (size == 0) {
            return false;
        }
        head = (head + 1) % capacity;
        size--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(tail - 1 + capacity) % capacity];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

// @lc code=start
// 2. 双向链表实现
// 2023-11-23 submission
// 58/58 cases passed
// Runtime: 20 ms, faster than 53.94% of cpp online submissions.
// Memory Usage: 17.3 MB, less than 6.7% of cpp online submissions.
class DoubleListNode {
public:
    int val;
    DoubleListNode* prev;
    DoubleListNode* next;
    DoubleListNode(int val) : val(val), prev(nullptr), next(nullptr) {
    }
};
class MyCircularQueue {
private:
    DoubleListNode* dummyHead;
    DoubleListNode* dummyTail;
    int size;
    int capacity;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : size(0), capacity(k) {
        dummyHead = new DoubleListNode(-1);
        dummyTail = new DoubleListNode(-1);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    ~MyCircularQueue() {
        DoubleListNode* node = dummyHead;
        while (node != nullptr) {
            DoubleListNode* next = node->next;
            delete node;
            node = next;
        }
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        DoubleListNode* node = new DoubleListNode(value);
        node->next = dummyTail;
        node->prev = dummyTail->prev;
        dummyTail->prev->next = node;
        dummyTail->prev = node;
        size++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        DoubleListNode* node = dummyHead->next;
        dummyHead->next = node->next;
        node->next->prev = dummyHead;
        delete node;
        size--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return dummyHead->next->val;
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return dummyTail->prev->val;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
    }
};
// @lc code=end
