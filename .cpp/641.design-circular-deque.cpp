/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
// 2023-11-23 submission
// 51/51 cases passed
// Runtime: 32 ms, faster than 7.39% of cpp online submissions.
// Memory Usage: 17.4 MB, less than 5.88% of cpp online submissions.
class DoubleListNode {
public:
    int val;
    DoubleListNode* prev;
    DoubleListNode* next;
    DoubleListNode(int val) : val(val), prev(nullptr), next(nullptr) {
    }
};

class MyCircularDeque {
private:
    DoubleListNode* head;
    DoubleListNode* tail;
    int size;
    int capacity;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        head = new DoubleListNode(-1);
        tail = new DoubleListNode(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
        capacity = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        DoubleListNode* node = new DoubleListNode(value);
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        DoubleListNode* node = new DoubleListNode(value);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        DoubleListNode* node = head->next;
        head->next = node->next;
        node->next->prev = head;
        delete node;
        size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        DoubleListNode* node = tail->prev;
        tail->prev = node->prev;
        node->prev->next = tail;
        delete node;
        size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return head->next->val;
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return tail->prev->val;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

// @lc code=start
// 2. 双向链表实现
// 2023-11-23 submission
// 51/51 cases passed
// Runtime: 25 ms, faster than 29.82% of cpp online submissions.
// Memory Usage: 17.1 MB, less than 13.95% of cpp online submissions.
class MyCircularDeque {
private:
    vector<int> data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        data.resize(k);
        front = 0;
        rear = 0;
        size = 0;
        capacity = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return data[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(rear - 1 + capacity) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
    }
};
// @lc code=end
