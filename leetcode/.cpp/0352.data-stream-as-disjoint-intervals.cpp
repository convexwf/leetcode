/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
// 1. 有序集合
// 2025-02-20 submission
// 7/7 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 10.8 MB, less than 93.85% of cpp online submissions.
class SummaryRanges {
public:
    SummaryRanges() {
    }

    void addNum(int val) {
        auto it = intervals.upper_bound(val);
        if (it != intervals.begin() && (--it)->second + 1 < val) {
            it++;
        }
        int l = val, r = val;
        while (it != intervals.end() && it->first <= val + 1 && it->second >= val - 1) {
            l = min(l, it->first);
            r = max(r, it->second);
            it = intervals.erase(it);
        }
        intervals[l] = r;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (const auto& [l, r] : intervals) {
            res.push_back({l, r});
        }
        return res;
    }

private:
    map<int, int> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
