/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
// 1. 栈
// 2025-03-18 submission
// 73/73 cases passed
// Runtime: 84 ms, faster than 17.44% of cpp online submissions.
// Memory Usage: 95.26 MB, less than 20.61% of cpp online submissions.
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        backHistory.push(homepage);
    }

    void visit(string url) {
        backHistory.push(url);
        while (!forwardHistory.empty()) {
            forwardHistory.pop();
        }
    }

    string back(int steps) {
        while (steps-- && backHistory.size() > 1) {
            forwardHistory.push(backHistory.top());
            backHistory.pop();
        }
        return backHistory.top();
    }

    string forward(int steps) {
        while (steps-- && !forwardHistory.empty()) {
            backHistory.push(forwardHistory.top());
            forwardHistory.pop();
        }
        return backHistory.top();
    }

private:
    stack<string> backHistory, forwardHistory;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
