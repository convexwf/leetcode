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

// @lc code=start
// 2. 二分查找
// 2024-08-05 submission
// 68/68 cases passed
// Runtime: 108 ms, faster than 66.84% of cpp online submissions.
// Memory Usage:  MB, less than 9.04% of cpp online submissions.
class RecentCounter {
public:
    RecentCounter() {
    }

    int ping(int t) {
        vec.push_back(t);
        int l = 0, r = vec.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (vec[mid] < t - 3000) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return vec.size() - l;
    }

private:
    vector<int> vec;
};
// @lc code=end
