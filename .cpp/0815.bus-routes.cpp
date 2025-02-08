/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
// 1. bfs
// 2025-02-08 submission
// 54/54 cases passed
// Runtime: 91 ms, faster than 95.21% of cpp online submissions.
// Memory Usage: 67.4 MB, less than 51.16% of cpp online submissions.
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        int n = routes.size();
        unordered_map<int, vector<int>> station2routes;
        for (int i = 0; i < n; ++i) {
            for (int station : routes[i]) {
                station2routes[station].push_back(i);
            }
        }

        if (!station2routes.count(source) || !station2routes.count(target)) {
            return -1;
        }

        queue<int> q;
        unordered_set<int> busVisited;
        unordered_set<int> stationVisited;
        q.push(source);
        stationVisited.insert(source);

        int step = 0;
        while (!q.empty()) {
            ++step;
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i) {
                int station = q.front();
                q.pop();
                for (int bus : station2routes[station]) {
                    if (busVisited.count(bus)) {
                        continue;
                    }
                    busVisited.insert(bus);
                    for (int nextStation : routes[bus]) {
                        if (stationVisited.count(nextStation)) {
                            continue;
                        }
                        if (nextStation == target) {
                            return step;
                        }
                        q.push(nextStation);
                        stationVisited.insert(nextStation);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
