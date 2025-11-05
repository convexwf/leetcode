/*
 * @lc app=leetcode id=635 lang=cpp
 *
 * [635] Design Log Storage System
 */

// @lc code=start
// 1. 字符串比较+二分查找+有序字典
class LogSystem {
public:
    LogSystem() {
        dict = {{"Year", 4},  {"Month", 7},   {"Day", 10},
                {"Hour", 13}, {"Minute", 16}, {"Second", 19}};
    }

    void put(int id, string timestamp) {
        logs[timestamp] = id;
    }

    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> res;
        int n = dict[granularity];
        string s = start.substr(0, n);
        string e = end.substr(0, n);
        for (auto it = logs.lower_bound(s); it != logs.end() && it->first.substr(0, n) <= e; ++it) {
            res.push_back(it->second);
        }
        return res;
    }

private:
    map<string, int> dict;
    map<string, int> logs;
};
// @lc code=end
