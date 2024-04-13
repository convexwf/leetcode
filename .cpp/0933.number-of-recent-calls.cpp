/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
// 1. 队列
// 2023-07-25 submission
// 68/68 cases passed
// Runtime: 141 ms, faster than 96.42% of cpp online submissions.
// Memory Usage: 57.2 MB, less than 83.21% of cpp online submissions.
class RecentCounter {
public:
    RecentCounter() {
    }

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }

private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
