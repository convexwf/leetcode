/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
// 2022-08-27 submission
// 17/17 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.9 MB, less than 58.81% of C++ online submissions.
class MyStack {
public:
    MyStack() {}
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; ++i) {
            q.push(q.front()); q.pop();
        }
    }
    int pop() {
        int x = q.front(); q.pop();
        return x;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

// @lc code=start
// 2022-08-27 submission
// 17/17 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7 MB, less than 20.63% of C++ online submissions.
class MyStack {
public:
    MyStack() {}
    void push(int x) {
        q2.push(x);
        while (q2.size() > 1) {
            q1.push(q2.front()); q2.pop();
        }
    }
    int pop() {
        int x = top(); q2.pop();
        return x;
    }
    int top() {
        if (q2.empty()) {
            for (int i = 0; i < (int)q1.size() - 1; ++i) {
                q1.push(q1.front()); q1.pop();
            }
            q2.push(q1.front()); q1.pop();
        }
        return q2.front();
    }
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1, q2;
};
// @lc code=end

// @lc code=start
// 2022-08-27 submission
// 17/17 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.9 MB, less than 58.81% of C++ online submissions.
class MyStack {
public:
    MyStack() {}

    void push(int val) {
        topVal = val;
        q.push(val);
    }

    int pop() {
        int q_size = q.size();
        while (q_size > 1) {
            topVal = q.front();
            q.push(q.front());
            q.pop();
            --q_size;
        }

        int pop_val = q.front();
        q.pop();
        return pop_val;
    }

    int top() {
        return topVal;
    }

    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
    int topVal;
};
// @lc code=end