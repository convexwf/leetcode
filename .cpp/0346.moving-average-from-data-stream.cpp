/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 */

// @lc code=start
// 1. 队列
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->n = 0;
        this->sum = 0;
    }

    double next(int val) {
        if (n < size) {
            n++;
        }
        else {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum / n;
    }

private:
    int size;
    int n;
    int sum;
    queue<int> q;
};
// @lc code=end
