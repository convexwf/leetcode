/*
 * @lc app=leetcode id=411 lang=cpp
 *
 * [411] Minimum Unique Word Abbreviation
 */

// @lc code=start
// 1. 位操作+最小堆
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int n = target.size();
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
        for (int mask = 0; mask < (1 << n); mask++) {
            string abbr;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (cnt > 0) {
                        abbr += to_string(cnt);
                        cnt = 0;
                    }
                    abbr += target[i];
                }
                else {
                    cnt++;
                }
            }
            if (cnt > 0) {
                abbr += to_string(cnt);
            }
            pq.push({abbr.size(), abbr});
        }
        while (!pq.empty()) {
            string abbr = pq.top().second;
            pq.pop();
            bool valid = true;
            for (const string& word : dictionary) {
                if (validWordAbbreviation(word, abbr)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return abbr;
            }
        }
        return "";
    }

    bool validWordAbbreviation(const string& word, const string& abbr) {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') {
                    return false;
                }
                int num = 0;
                while (j < n && isdigit(abbr[j])) {
                    num = num * 10 + abbr[j++] - '0';
                }
                i += num;
            }
            else {
                if (word[i++] != abbr[j++]) {
                    return false;
                }
            }
        }
        return i == m && j == n;
    }
};
// @lc code=end
