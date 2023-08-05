/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
// 1. 栈
// 2023-08-02 submission
// 120/120 cases passed
// Runtime: 18 ms, faster than 81.25% of cpp online submissions.
// Memory Usage:  MB, less than 99.22% of cpp online submissions.
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int pre_time = 0, id = 0, time = 0;
        string status;
        for (auto log : logs) {
            extract_log(log, id, status, time);
            if (!st.empty()) {
                res[st.top()] += time - pre_time;
            }
            pre_time = time;
            if (status == "start") {
                st.push(id);
            }
            else {
                res[st.top()]++;
                st.pop();
                pre_time++;
            }
        }
        return res;
    }

    void extract_log(string log, int& id, string& status, int& time) {
        int pos1 = log.find(":");
        int pos2 = log.find_last_of(":");
        id = stoi(log.substr(0, pos1));
        status = log.substr(pos1 + 1, pos2 - pos1 - 1);
        time = stoi(log.substr(pos2 + 1));
    }
};
// @lc code=end
