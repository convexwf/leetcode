/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// @lc code=start
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
