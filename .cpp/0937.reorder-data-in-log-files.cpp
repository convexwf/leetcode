/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

// @lc code=start
// 1. 自定义排序
// 2023-09-25 submission
// 65/65 cases passed
// Runtime: 8 ms, faster than 71.2% of cpp online submissions.
// Memory Usage: 11.2 MB, less than 76.12% of cpp online submissions.
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> resLogs, digitLogs;
        vector<vector<string>> letterLogs;
        for (int i = 0; i < logs.size(); ++i) {
            int pos = logs[i].find(' ');
            if (isalpha(logs[i][pos + 1])) {
                letterLogs.push_back({logs[i].substr(0, pos), logs[i].substr(pos + 1)});
            }
            else {
                digitLogs.push_back(logs[i]);
            }
        }
        sort(letterLogs.begin(), letterLogs.end(), [](vector<string>& a, vector<string>& b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        for (int i = 0; i < letterLogs.size(); ++i) {
            resLogs.push_back(letterLogs[i][0] + " " + letterLogs[i][1]);
        }
        for (int i = 0; i < digitLogs.size(); ++i) {
            resLogs.push_back(digitLogs[i]);
        }
        return resLogs;
    }
};
// @lc code=end
