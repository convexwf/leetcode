/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 */

// @lc code=start
// 1. 哈希表
// 2023-08-15 submission
// 267/267 cases passed
// Runtime: 3 ms, faster than 78.5% of cpp online submissions.
// Memory Usage:  MB, less than 68.24% of cpp online submissions.
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        // convert cells to char
        char state = 0;
        for (int i = 0; i < 8; ++i) {
            if (cells[i] == 1) {
                state |= (1 << i);
            }
        }
        // simulate
        unordered_map<char, int> hash;
        while (n--) {
            if (hash.count(state)) {
                n %= hash[state] - n;
            }
            hash[state] = n;
            state = nextDay(state);
        }
        // convert char to vector<int>
        vector<int> res(8, 0);
        for (int i = 0; i < 8; ++i) {
            if (state & (1 << i)) {
                res[i] = 1;
            }
        }
        return res;
    }

private:
    char nextDay(char state) {
        char res = 0;
        for (int i = 1; i < 7; ++i) {
            if (((state >> (i - 1)) & 1) == ((state >> (i + 1)) & 1)) {
                res |= (1 << i);
            }
        }
        return res;
    }
};
// @lc code=end
