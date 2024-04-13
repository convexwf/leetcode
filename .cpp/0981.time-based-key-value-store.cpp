/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
// 1. 哈希表+二分查找
// 2023-07-21 submission
// 50/50 cases passed
// Runtime: 312 ms, faster than 96.79% of cpp online submissions.
// Memory Usage: 128.5 MB, less than 93.6% of cpp online submissions.
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (!m.count(key)) return "";
        auto& pairs = m[key];
        int n = pairs.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (pairs[mid].first <= timestamp)
                left = mid + 1;
            else
                right = mid;
        }
        return right == 0 ? "" : pairs[right - 1].second;
        //// use upper_bound
        // auto it = m.find(key);
        // if (it == m.end()) return "";
        // auto& pairs = it->second;
        // auto it2 = upper_bound(pairs.begin(), pairs.end(), timestamp, [](int val, const pair<int,
        // string>& p) {
        //     return val < p.first;
        // });
        // if (it2 == pairs.begin()) return "";
        // return prev(it2)->second;

        //// use right = n - 1
        // int left = 0, right = n - 1;
        // while (left < right) {
        //     int mid = left + (right - left + 1) / 2;
        //     if (pairs[mid].first <= timestamp) left = mid;
        //     else right = mid - 1;
        // }
        // return pairs[left].first <= timestamp ? pairs[left].second : "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

// @lc code=start
// 2. 哈希表+map
// 2023-07-21 submission
// 50/50 cases passed
// Runtime: 383 ms, faster than 34.96% of cpp online submissions.
// Memory Usage: 131.1 MB, less than 25.13% of cpp online submissions.
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";
        auto it = m[key].upper_bound(timestamp);
        if (it == m[key].begin()) return "";
        return (--it)->second;
    }

private:
    unordered_map<string, map<int, string>> m;
};
// @lc code=end
