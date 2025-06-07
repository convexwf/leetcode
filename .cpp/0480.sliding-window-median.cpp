/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start
// 1. 多重有序集合
// 2023-11-17 submission
// 43/43 cases passed
// Runtime: 125 ms, faster than 47.28% of cpp online submissions.
// Memory Usage: 46.1 MB, less than 33.43% of cpp online submissions.
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small, large;
        vector<double> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (small.count(nums[i - k])) {
                    small.erase(small.find(nums[i - k]));
                }
                else {
                    large.erase(large.find(nums[i - k]));
                }
            }
            if (small.size() <= large.size()) {
                if (large.empty() || nums[i] <= *large.begin()) {
                    small.insert(nums[i]);
                }
                else {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            }
            else {
                if (nums[i] >= *small.rbegin()) {
                    large.insert(nums[i]);
                }
                else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }
            if (i >= k - 1) {
                if (k & 1) {
                    res.push_back(*small.rbegin());
                }
                else {
                    res.push_back(((double)*small.rbegin() + *large.begin()) / 2);
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 多重有序集合-另一种解法
// 2025-06-04 submission
// 44/44 cases passed
// Runtime: 47 ms, faster than 75.36% of cpp online submissions.
// Memory Usage:  MB, less than 60.6% of cpp online submissions.
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        for (int i = k;; ++i) {
            // get the median
            if (k % 2 == 0) {
                res.push_back((*mid + *prev(mid, 1)) / 2.0);
            }
            else {
                res.push_back(*mid);
            }
            // if we reach the end of the array, break
            if (i == nums.size()) break;

            // insert the next element and remove the oldest element
            window.insert(nums[i]);
            if (nums[i] < *mid) {
                --mid;
            }
            if (nums[i - k] <= *mid) {
                ++mid;
            }
            window.erase(window.lower_bound(nums[i - k]));
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 最大堆+最小堆+延迟删除
// 2025-06-04 submission
// 44/44 cases passed
// Runtime: 45 ms, faster than 100% of cpp online submissions.
// Memory Usage: 40.1 MB, less than 82.09% of cpp online submissions.
class MedianFinder {
public:
    MedianFinder(int k) {
        this->k = k;
    }

    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        }
        else {
            large.push(num);
            ++largeSize;
        }
        reblance();
    }

    void removeNum(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        }
        else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        reblance();
    }

    double findMedian() {
        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2.0;
    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;
    int smallSize = 0;
    int largeSize = 0;
    int k;

    template <typename T>
    void prune(T& pq) {
        while (!pq.empty() && delayed[pq.top()]) {
            if (--delayed[pq.top()] == 0) {
                delayed.erase(pq.top());
            }
            pq.pop();
        }
    }

    void reblance() {
        if (smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        }
        else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            prune(large);
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        MedianFinder finder(k);
        for (int i = 0; i < k; ++i) {
            finder.addNum(nums[i]);
        }
        vector<double> ans = {finder.findMedian()};
        for (int i = k; i < nums.size(); ++i) {
            finder.addNum(nums[i]);
            finder.removeNum(nums[i - k]);
            ans.push_back(finder.findMedian());
        }
        return ans;
    }
};
// @lc code=end
