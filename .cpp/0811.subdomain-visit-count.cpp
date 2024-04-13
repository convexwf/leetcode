/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */

// @lc code=start
// 1. 哈希表
// 2023-11-07 submission
// 52/52 cases passed
// Runtime: 14 ms, faster than 44.14% of cpp online submissions.
// Memory Usage: 11.8 MB, less than 70.15% of cpp online submissions.
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (string& cpdomain : cpdomains) {
            int i = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, i));
            string domain = cpdomain.substr(i + 1);
            for (int i = domain.size() - 1; i >= 0; --i) {
                if (domain[i] == '.') {
                    m[domain.substr(i + 1)] += count;
                }
                else if (i == 0) {
                    m[domain] += count;
                }
            }
        }
        vector<string> res;
        for (auto& [domain, count] : m) {
            res.push_back(to_string(count) + " " + domain);
        }
        return res;
    }
};
// @lc code=end
