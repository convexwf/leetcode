/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
// 1. 两个栈
// 2022-08-27 submission
// 22/22 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7 MB, less than 57.21% of cpp online submissions.
class MyQueue {
public:
    MyQueue() {
    }

    void push(int value) {
        stk1.push(value);
    }

    int pop() {
        if (stk1.empty() && stk2.empty()) return -1;
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int res = stk2.top();
        stk2.pop();
        return res;
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }

    int peek() {
        if (stk1.empty() && stk2.empty()) return -1;
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }

private:
    stack<int> stk1;
    stack<int> stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

// @lc code=start
// 2. 单个栈
// 2024-10-09 submission
// 22/22 cases passed
// Runtime: 0 ms, faster than % of cpp online submissions.
// Memory Usage: 8.8 MB, less than 22.01% of cpp online submissions.
class MyQueue {
public:
    stack<int> stk;

    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stackToTmp();
        int res = tmp.top();
        tmp.pop();
        tmpToStack();
        return res;
    }

    /** Get the front element. */
    int peek() {
        stackToTmp();
        int res = tmp.top();
        tmpToStack();
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }

private:
    stack<int> tmp;

    void stackToTmp() {
        while (!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
    }

    void tmpToStack() {
        while (!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }
};
// @lc code=end
