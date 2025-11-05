/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
// 1. 堆
// 2022-08-26 submission
// 21/21 cases passed
// Runtime: 483 ms, faster than 61.29% of cpp online submissions.
// Memory Usage: 117.1 MB, less than 65.81% of cpp online submissions.
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (small.size() == big.size()) {
            small.push(num);
            big.push(small.top());
            small.pop();
        }
        else {
            big.push(num);
            small.push(big.top());
            big.pop();
        }
    }

    double findMedian() {
        if ((small.size() + big.size()) % 2 == 0) {
            return ((double)small.top() + big.top()) / 2;
        }
        else {
            return big.top();
        }
    }

    priority_queue<int, vector<int>, less<int>> big;
    priority_queue<int, vector<int>, greater<int>> small;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
