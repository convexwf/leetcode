/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
// 2022-08-26 submission
// 596/596 cases passed
// Runtime: 18 ms, faster than 54.78% of C++ online submissions.
// Memory Usage: 9.6 MB, less than 31.45% of C++ online submissions.
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        int cur = 0;
        for (int i = 1; i < n; i++) {
            cur = min(min(res[i2] * 2, res[i3] * 3), res[i5] * 5);
            res.push_back(cur);
            if (cur == res[i2] * 2) i2++;
            if (cur == res[i3] * 3) i3++;
            if (cur == res[i5] * 5) i5++;
            // cout << cur << " " << i2 << " " << i3 << " " << i5 <<endl;
        }
        return res[n - 1];
    }
};
// @lc code=end

// @lc code=start
// 2022-08-26 submission
// 596/596 cases passed
// Runtime: 95 ms, faster than 28.02% of C++ online submissions.
// Memory Usage: 10.6 MB, less than 27.13% of C++ online submissions.
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        for (long i = 1; i < n; ++i) {
            long t = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == t) {
                t = pq.top();
                pq.pop();
            }
            pq.push(t * 2);
            pq.push(t * 3);
            pq.push(t * 5);
        }
        return pq.top();
    }
};
// @lc code=end
