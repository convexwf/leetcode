/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
// 1. DFS + multiset
// 2023-10-04 submission
// 81/81 cases passed
// Runtime: 22 ms, faster than 30.64% of cpp online submissions.
// Memory Usage:  MB, less than 40.53% of cpp online submissions.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> targets;
        vector<string> route;
        for (auto& t : tickets) {
            targets[t[0]].insert(t[1]);
        }
        visit(targets, "JFK", route);
        return vector<string>(route.rbegin(), route.rend());
    }

private:
    void visit(unordered_map<string, multiset<string>>& targets, string airport,
               vector<string>& route) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(targets, next, route);
        }
        route.push_back(airport);
    }
};
// @lc code=end

// @lc code=start
// 2. 栈 + multiset
// 2023-10-04 submission
// 81/81 cases passed
// Runtime: 18 ms, faster than 58.65% of cpp online submissions.
// Memory Usage: 14.6 MB, less than 62.81% of cpp online submissions.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        vector<string> ans;
        stack<string> stk;
        stk.push("JFK");
        while (!stk.empty()) {
            string from = stk.top();
            if (graph[from].empty()) {
                ans.push_back(from);
                stk.pop();
            }
            else {
                auto to = graph[from].begin();
                stk.push(*to);
                graph[from].erase(to);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
