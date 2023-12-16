/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 */

// @lc code=start
// 1. 哈希表+排序
// 2023-12-11 submission
// 58/58 cases passed
// Runtime: 56 ms, faster than 90.91% of cpp online submissions.
// Memory Usage: 42.3 MB, less than 74.24% of cpp online submissions.
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes) {
        unordered_map<int, int> m;
        for (int barcode : barcodes) {
            m[barcode]++;
        }
        vector<pair<int, int>> v;
        for (auto &p : m) {
            v.push_back({p.second, p.first});
        }
        sort(v.begin(), v.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first; });
        vector<int> res(barcodes.size());
        int index = 0;
        for (auto &p : v) {
            for (int i = 0; i < p.first; i++) {
                res[index] = p.second;
                index += 2;
                if (index >= barcodes.size()) {
                    index = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
