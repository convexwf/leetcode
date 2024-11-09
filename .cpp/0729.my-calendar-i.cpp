/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
// 1. 线性搜索
// 2023-08-24 submission
// 107/107 cases passed
// Runtime: 83 ms, faster than 78.19% of cpp online submissions.
// Memory Usage: 37.5 MB, less than 88.96% of cpp online submissions.
class MyCalendar {
public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        for (const pair<int, int> &p : books) {
            if (max(p.first, start) < min(p.second, end)) {
                return false;
            }
        }
        books.push_back({start, end});
        return true;
    }

private:
    vector<pair<int, int>> books;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

// @lc code=start
// 2. 二分搜索
// 2023-08-24 submission
// 107/107 cases passed
// Runtime: 85 ms, faster than 75.76% of cpp online submissions.
// Memory Usage: 37.6 MB, less than 82.46% of cpp online submissions.
class MyCalendar {
public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        int l = 0, r = books.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (books[m].first >= end) {
                r = m;
            }
            else if (books[m].second <= start) {
                l = m + 1;
            }
            else {
                return false;
            }
        }
        books.insert(books.begin() + l, {start, end});
        return true;
    }

private:
    vector<pair<int, int>> books;
};
// @lc code=end

// @lc code=start
// 3. 有序集合
// 2023-08-24 submission
// 107/107 cases passed
// Runtime: 81 ms, faster than 81.21% of cpp online submissions.
// Memory Usage: 38.8 MB, less than 42.71% of cpp online submissions.
class MyCalendar {
public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        auto it = intervals.lower_bound(start);
        if (it != intervals.end() && it->first < end) return false;
        if (it != intervals.begin() && (--it)->second > start) return false;
        intervals.insert({start, end});
        return true;
    }

private:
    map<int, int> intervals;
};
// @lc code=end
