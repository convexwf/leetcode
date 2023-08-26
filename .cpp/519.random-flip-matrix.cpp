/*
 * @lc app=leetcode id=519 lang=cpp
 *
 * [519] Random Flip Matrix
 */

// @lc code=start
// 1. Fisher-Yates 洗牌算法
// 2023-08-23 submission
// 20/20 cases passed
// Runtime: 16 ms, faster than 68.16% of cpp online submissions.
// Memory Usage: 18.6 MB, less than 91.54% of cpp online submissions.
class Solution {
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
    }

    vector<int> flip() {
        int id = rand() % total, val = id;
        total--;
        if (rMap.count(id)) id = rMap[id];
        rMap[val] = rMap.count(total) ? rMap[total] : total;
        return {id / n, id % n};
    }

    void reset() {
        rMap.clear();
        total = m * n;
    }

private:
    int m, n, total;
    unordered_map<int, int> rMap;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end
