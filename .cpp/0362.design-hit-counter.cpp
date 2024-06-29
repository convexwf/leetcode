/*
 * @lc app=leetcode id=362 lang=cpp
 *
 * [362] Design Hit Counter
 */

// @lc code=start
// 1. 数组+二分查找
class HitCounter {
public:
    vector<int> hits;
    HitCounter() {
    }

    void hit(int timestamp) {
        hits.push_back(timestamp);
    }

    int getHits(int timestamp) {
        // upper_bound 返回第一个大于 timestamp 的元素的位置
        int a = upper_bound(hits.begin(), hits.end(), timestamp) - hits.begin();
        // lower_bound 返回第一个大于等于 timestamp - 300 的元素的位置
        int b = lower_bound(hits.begin(), hits.end(), timestamp - 300) - hits.begin();
        return a - b;
    }
};
// @lc code=end

// @lc code=start
// 2. 计数+二分查找
class HitCounter {
public:
    HitCounter() {
    }

    void hit(int timestamp) {
        total_hits++;
        if (hits.empty() || hits.back().first != timestamp) {
            hits.push_back({timestamp, total_hits});
        }
        else {
            hits.back().second = total_hits;
        }
    }

    int getHits(int timestamp) {
        // use lower_bound to find the first element >= timestamp - 300
        auto it1 = lower_bound(hits.begin(), hits.end(), make_pair(timestamp - 300, 0));
        // use upper_bound to find the first element > timestamp
        auto it2 = upper_bound(hits.begin(), hits.end(), make_pair(timestamp, 0));
        // TODO: check if it1 and it2 are valid
        return it2->second - it1->second;
    }

private:
    vector<pair<int, int>> hits;
    int total_hits = 0;
};
// @lc code=end
