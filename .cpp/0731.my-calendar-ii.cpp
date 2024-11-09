/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
// 1. 差分数组 Memory Limit Exceeded
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        diff.resize(1000000001);
    }

    bool book(int start, int end) {
        ++diff[start];
        --diff[end];
        int cnt = 0;
        for (int i = 0; i < diff.size(); ++i) {
            cnt += diff[i];
            if (cnt > 2) {
                --diff[start];
                ++diff[end];
                return false;
            }
        }
        return true;
    }

private:
    vector<int> diff;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
