/*
 * @lc app=leetcode id=420 lang=cpp
 *
 * [420] Strong Password Checker
 */

// @lc code=start
// 1. 堆
// 2025-06-03 submission
// 54/54 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 38.31% of cpp online submissions.
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        int res = 0, shortLen = 0, extraLen = 0;

        // The length of the password must be
        // between 6 and 20 characters.
        int shortLen = 0, extraLen = 0;
        if (n < 6) {
            shortLen = 6 - n;
        }
        if (n > 20) {
            extraLen = n - 20;
        }

        // minimum requirement is must have 3 type of chars
        int missingChars = 3;
        bool hasDigit = false, hasUpper = false, hasLower = false;
        for (char ch : password) {
            if (isdigit(ch) && !hasDigit) {
                missingChars--;
                hasDigit = true;
            }
            if (isupper(ch) && !hasUpper) {
                missingChars--;
                hasUpper = true;
            }
            if (islower(ch) && !hasLower) {
                missingChars--;
                hasLower = true;
            }
            if (missingChars == 0) break;
        }

        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_q(cmp);

        // fill priority queue with the sizes of the repeating characters
        // and their sizes modulo 3
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (i < n && password[j] == password[i]) {
                i++;
            }
            if (i - j >= 3) {
                min_q.push(make_pair((i - j) % 3, i - j));
            }
            j = i;
        }

        // try to reduce the size of repeating characters
        int len = extraLen;
        while (!min_q.empty() && len != 0) {
            int size = min_q.top().second - 1; // reduce size greedly
            min_q.pop();
            min_q.push({size % 3, size});
            len--;
        }

        // transfer the min_q to max_q to get the maximum length of repeating characters
        priority_queue<int> max_q;
        while (!min_q.empty()) {
            max_q.push(min_q.top().second); // Push only length
            min_q.pop();
        }

        // try to replace the repeating characters
        // with the minimum number of replacements
        int replaces = 0;
        while (!max_q.empty() && max_q.top() >= 3) {
            int len = max_q.top() - 3;
            max_q.pop();
            max_q.push(len);
            replaces++;
        }

        // Total changes = extra deletions + max of needed replacements, insertions(shortLen), or
        // missing types.
        res = extraLen + max(replaces, max(shortLen, missingChars));

        return res;
    }
};
// @lc code=end
