/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
// 2. 贪心 + 二分查找
// 2023-05-12 submission
// 87/87 cases passed
// Runtime: 388 ms, faster than 67.67% of cpp online submissions.
// Memory Usage: 77.5 MB, less than 90.91% of cpp online submissions.
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b){
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] > b[1];
        });
        vector<int> tails(n, 0);
        int size = 0;
        for (int i = 0; i < n; i++) {
            int left = 0, right = size;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tails[mid] < envelopes[i][1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            tails[left] = envelopes[i][1];
            if (left == size) size++;
        }
        return size;
    }
};
// @lc code=end

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b){
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        });
        vector<int> dp;
        for (vector<int>& e : envelopes) {
            if(dp.empty() || dp.back() < e[1]) {
                dp.push_back(e[1]);
            }
            else {
                int pos = lower_bound(dp.begin(), dp.end(), e[1]) - dp.begin();
                dp[pos] = e[1];
            }
        }
        return dp.size();
    }
};
// @lc code=end