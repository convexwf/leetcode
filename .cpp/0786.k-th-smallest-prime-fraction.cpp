/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */

// @lc code=start
// 1. 最大堆
// 2023-06-01 submission
// 59/59 cases passed
// Runtime: 212 ms, faster than 89.78% of cpp online submissions.
// Memory Usage: 34.9 MB, less than 81.33% of cpp online submissions.
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first * b.second < a.second * b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        int a = 0, b = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                a = arr[i], b = arr[j];
                if (pq.size() < k) {
                    pq.push({a, b});
                }
                else if (cmp({a, b}, pq.top())) {
                    pq.pop();
                    pq.push({a, b});
                }
            }
        }
        return {pq.top().first, pq.top().second};
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找+双指针
// 2023-06-01 submission
// 59/59 cases passed
// Runtime: 8 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 99.11% of cpp online submissions.
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        int n = arr.size();
        while (l < r) {
            double mid = (l + r) / 2;
            int cnt = 0;
            int p = 0, q = 1;
            for (int i = 0, j = 1; i < n; ++i) {
                while (j < n && arr[i] > mid * arr[j]) ++j;
                cnt += n - j;
                if (j < n && p * arr[j] < q * arr[i]) {
                    p = arr[i];
                    q = arr[j];
                }
            }
            if (cnt == k) {
                return {p, q};
            }
            else if (cnt < k) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return {};
    }
};
// @lc code=end
