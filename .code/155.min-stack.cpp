/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
// 2023-01-14 submission
// 31/31 cases passed
// Runtime: 24 ms, faster than 78.28% of C++ online submissions.
// Memory Usage: 16.4 MB, less than 65.11% of C++ online submissions.
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        base.push(val);
        if (min_s.empty() || min_s.top() >= val) {
            min_s.push(val);
        }
    }

    void pop() {
        if (min_s.top() == base.top()) min_s.pop();
        base.pop();
    }

    int top() {
        return base.top();
    }

    int getMin() {
        return min_s.top();
    }

private:
    stack<int> base;
    stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 31/31 cases passed
// Runtime: 25 ms, faster than 74.45% of C++ online submissions.
// Memory Usage: 16.4 MB, less than 65.11% of C++ online submissions.
class MinStack {
public:
    MinStack() {
        min_val = INT_MAX;
    }
    void push(int x) {
        if (x <= min_val) {
            st.push(min_val);
            min_val = x;
        }
        st.push(x);
    }
    void pop() {
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
        }
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return min_val;
    }

private:
    int min_val;
    stack<int> st;
};
// @lc code=end