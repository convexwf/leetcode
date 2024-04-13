/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
// 2020-11-11 submission
// 81/81 cases passed
// Runtime: 3 ms, faster than 75.64% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 98.33% of cpp online submissions.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h_idx = 1;
        for (; h_idx <= citations.size(); h_idx++) {
            if (h_idx > citations[h_idx - 1]) break;
        }
        return h_idx - 1;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-30 submission
// 81/81 cases passed
// Runtime: 7 ms, faster than 33.44% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 16.64% of cpp online submissions.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        for (int c : citations) {
            if (c >= n) {
                buckets[n]++;
            }
            else {
                buckets[c]++;
            }
        }
        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += buckets[i];
            if (count >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end
