/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
// 1. 排序+贪心算法
// 2023-07-27 submission
// 48/48 cases passed
// Runtime: 238 ms, faster than 51.12% of cpp online submissions.
// Memory Usage: 85.8 MB, less than 37.46% of cpp online submissions.
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        sort(cars.begin(), cars.end());
        int ans = 0;
        double cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (cars[i].second > cur) {
                ans++;
                cur = cars[i].second;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 有序字典
// 2023-07-27 submission
// 48/48 cases passed
// Runtime: 353 ms, faster than 16.67% of cpp online submissions.
// Memory Usage: 96.5 MB, less than 10.07% of cpp online submissions.
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0;
        double cur = 0;
        map<int, double> pos2time;
        for (int i = 0; i < position.size(); ++i) {
            // 使用负数作为 key，是为了让 map 按照从大到小的顺序遍历
            pos2time[-position[i]] = (double)(target - position[i]) / speed[i];
        }
        for (auto a : pos2time) {
            if (a.second <= cur) continue;
            cur = a.second;
            ++res;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 优先队列
// 2023-07-27 submission
// 48/48 cases passed
// Runtime: 296 ms, faster than 26.71% of cpp online submissions.
// Memory Usage: 78.5 MB, less than 80.4% of cpp online submissions.
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0;
        double cur = 0;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < position.size(); ++i) {
            q.push({position[i], speed[i]});
        }
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            double timeNeeded = (double)(target - t.first) / t.second;
            if (timeNeeded <= cur) continue;
            cur = timeNeeded;
            ++res;
        }
        return res;
    }
};
// @lc code=end
