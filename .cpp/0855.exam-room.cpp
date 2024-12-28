/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// @lc code=start
// 1. 有序集合
// 2023-09-13 submission
// 126/126 cases passed
// Runtime: 337 ms, faster than 81.4% of cpp online submissions.
// Memory Usage: 20.2 MB, less than 78.35% of cpp online submissions.
class ExamRoom {
public:
    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        int start = 0, mx = 0, idx = 0;
        for (int i : spots) {
            if (start == 0) {
                if (mx < i - start) {
                    mx = i - start;
                    idx = 0;
                }
            }
            else {
                if (mx < (i - start + 1) / 2) {
                    mx = (i - start + 1) / 2;
                    idx = start + mx - 1;
                }
            }
            start = i + 1;
        }
        if (start > 0 && mx < n - start) {
            mx = n - start;
            idx = n - 1;
        }
        spots.insert(idx);
        return idx;
    }

    void leave(int p) {
        spots.erase(p);
    }

private:
    int n;
    set<int> spots;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

// @lc code=start
// 2. 有序集合+自定义排序+哈希表
// 2024-12-25 submission
// 126/126 cases passed
// Runtime: 31 ms, faster than 86.27% of cpp online submissions.
// Memory Usage: 34.5 MB, less than 9.41% of cpp online submissions.

int N;

int dist(const pair<int, int>& p) {
    int l = p.first;
    int r = p.second;
    if (l == -1 || r == N) {
        return r - l - 1;
    }
    return (r - l) / 2;
}

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        int d1 = dist(a);
        int d2 = dist(b);
        if (d1 == d2) {
            return a.first < b.first;
        }
        return d1 > d2;
    }
};

class ExamRoom {
private:
    set<pair<int, int>, cmp> s;
    unordered_map<int, int> seat_left;
    unordered_map<int, int> seat_right;

    void add_interval(const pair<int, int>& p) {
        s.insert(p);
        seat_left[p.second] = p.first;
        seat_right[p.first] = p.second;
    }

    void remove_interval(const pair<int, int>& p) {
        s.erase(p);
        seat_left.erase(p.second);
        seat_right.erase(p.first);
    }

public:
    ExamRoom(int n) {
        N = n;
        s.insert({-1, n});
    }

    int seat() {
        auto p = *s.begin();
        int l = p.first;
        int r = p.second;
        int seat;
        if (l == -1) {
            seat = 0;
        }
        else if (r == N) {
            seat = N - 1;
        }
        else {
            seat = l + (r - l) / 2;
        }
        remove_interval(p);
        add_interval({l, seat});
        add_interval({seat, r});
        return seat;
    }

    void leave(int p) {
        int l = seat_left[p];
        int r = seat_right[p];
        remove_interval({l, p});
        remove_interval({p, r});
        add_interval({l, r});
    }
};
// @lc code=end
