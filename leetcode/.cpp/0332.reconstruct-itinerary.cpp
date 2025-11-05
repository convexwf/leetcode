/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
// 1. 排序+dfs
// 2023-10-04 submission
// 81/81 cases passed
// Runtime: 22 ms, faster than 30.64% of cpp online submissions.
// Memory Usage:  MB, less than 40.53% of cpp online submissions.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), greater<vector<string>>());
        unordered_map<string, vector<string>> graph;
        for (const vector<string>& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        vector<string> ans;
        function<void(const string&)> dfs = [&](const string& node) {
            while (graph[node].size() > 0) {
                string next = graph[node].back();
                graph[node].pop_back();
                dfs(next);
            }
            ans.push_back(node);
        };
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 排序+栈
// 2023-10-04 submission
// 81/81 cases passed
// Runtime: 18 ms, faster than 58.65% of cpp online submissions.
// Memory Usage: 14.6 MB, less than 62.81% of cpp online submissions.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), greater<vector<string>>());
        unordered_map<string, vector<string>> graph;
        for (const vector<string>& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
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
                stk.push(graph[from].back());
                graph[from].pop_back();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
